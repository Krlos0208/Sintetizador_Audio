/* tp-conn.c
 *
 * Copyright (C) 2005-2007 Nokia Corporation
 * Copyright (C) 2006-2007 Collabora Ltd. <http://www.collabora.co.uk/>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "tp-conn.h"

#include <string.h>

#include <telepathy-glib/dbus.h>

#include "tp-helpers.h"
#include "tp-connmgr.h"
#include "tp-props-iface.h"
#include "internal.h"
#include "_gen/add-signals.h"

G_DEFINE_TYPE (TpConn, tp_conn, DBUS_TYPE_G_PROXY);

typedef struct {
    TpConnection *connection;
} TpConnPrivate;

#define TP_CONN_PRIV(o) \
    (G_TYPE_INSTANCE_GET_PRIVATE (o, TELEPATHY_CONN_TYPE, TpConnPrivate))


/* We initialize the list of signatures here, so that we can use
 * it to add them for new interface instances later.
 */

/* FIXME: This should be replaced by a more automatic way of doing
 * this. The reason for using a set of function pointers is that there is no
 * apparent cleaner way of doing this, unless DBusGProxy gains a non-varargs
 * version of dbus_g_proxy_add_signal...
 */

static void
_tp_conn_init_interface_signal_signatures (GData **signal_sigs)
{
  g_datalist_init (signal_sigs);

  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_ALIASING,
      &tp_conn_set_aliasing_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_AVATARS,
      &tp_conn_set_avatars_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_CAPABILITIES,
      &tp_conn_set_capabilities_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_CONTACT_INFO,
      &tp_conn_set_contactinfo_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_FORWARDING,
      &tp_conn_set_forwarding_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_PRESENCE,
      &tp_conn_set_presence_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_PRIVACY,
      &tp_conn_set_privacy_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CONNECTION_INTERFACE_RENAMING,
      &tp_conn_set_renaming_signatures);
}


static void
tp_conn_init (TpConn *self)
{
  self->first_run = TRUE;
}


static void tp_conn_dispose (GObject *obj)
{
  TpConn *self = TELEPATHY_CONN (obj);

  if (self->first_run == TRUE)
    {
      TpConnPrivate *priv = TP_CONN_PRIV (self);

      self->first_run = FALSE;
      g_datalist_clear (&(self->interface_list));
      g_object_unref (priv->connection);
      priv->connection = NULL;
    }

  G_OBJECT_CLASS (tp_conn_parent_class)->dispose (obj);
}


static void tp_conn_class_init (TpConnClass *klass)
{
  GObjectClass *obj = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (TpConnPrivate));

  obj->dispose = tp_conn_dispose;
  _tp_register_marshallers ();
  _tp_conn_init_interface_signal_signatures (&(klass->iface_signal_sigs));
}


/* The interface name getters */

GQuark
tp_get_conn_interface (void)
{
  return tp_iface_quark_connection ();
}

GQuark
tp_get_conn_aliasing_interface (void)
{
  return tp_iface_quark_connection_interface_aliasing ();
}

GQuark
tp_get_conn_avatars_interface (void)
{
  return tp_iface_quark_connection_interface_avatars ();
}

GQuark
tp_get_conn_capabilities_interface (void)
{
  return tp_iface_quark_connection_interface_capabilities ();
}

GQuark
tp_get_conn_contactinfo_interface (void)
{
  return tp_iface_quark_connection_interface_contact_info ();
}

GQuark
tp_get_conn_forwarding_interface (void)
{
  return tp_iface_quark_connection_interface_forwarding ();
}

GQuark
tp_get_conn_presence_interface (void)
{
  return tp_iface_quark_connection_interface_presence ();
}

GQuark
tp_get_conn_privacy_interface (void)
{
  return tp_iface_quark_connection_interface_privacy ();
}

GQuark
tp_get_conn_renaming_interface (void)
{
  return tp_iface_quark_connection_interface_renaming ();
}


static gboolean tp_conn_status_change_handler (DBusGProxy *proxy,
    guint status, guint reason, gpointer user_data);


static TpConn *
_tp_conn_new (TpConnection *connection,
              guint *status,
              GError **error)
{
  TpProxy *conn_as_proxy = (TpProxy *) connection;
  gboolean connection_ready;
  guint conn_status = TP_CONNECTION_STATUS_DISCONNECTED;
  TpConn *obj;
  TpConnPrivate *priv;
  GError *err = NULL;

  g_return_val_if_fail (connection != NULL, NULL);

  /* Create the proxy object for this connection. It will be used to
     perform the actual method calls over D-BUS. */

  obj = g_object_new (TELEPATHY_CONN_TYPE,
      "name", conn_as_proxy->bus_name,
      "path", conn_as_proxy->object_path,
      "interface", TP_IFACE_CONNECTION,
      "connection", conn_as_proxy->dbus_connection,
      NULL);

  priv = TP_CONN_PRIV (obj);
  priv->connection = g_object_ref (connection);

  g_datalist_init (&(obj->interface_list));

  ADD_SIGNALS_FOR_CONNECTION (DBUS_G_PROXY (obj));

  g_object_get (connection,
      "connection-ready", &connection_ready,
      NULL);

  if (connection_ready)
    {
      gchar **interfaces;

      g_object_get (connection,
          "status", &conn_status,
          "interfaces", &interfaces,
          NULL);

      tp_conn_local_set_interfaces (obj, interfaces);
      g_strfreev (interfaces);
    }
  else if (!tp_conn_get_status (DBUS_G_PROXY (obj), &conn_status, &err))
    {
      g_propagate_error (error, err);
      g_object_unref (obj);
      return NULL;
    }
  else if (conn_status == TP_CONNECTION_STATUS_CONNECTED)
    {
      tp_conn_status_change_handler (DBUS_G_PROXY (obj), conn_status,
          0, NULL);
    }
  else
    {
      /* We can't use connection-ready because of our API guarantee that
       * by the time a later StatusChanged handler runs, we'll be ready -
       * connection-ready occurs some time after StatusChanged, because it
       * uses async calls */
      dbus_g_proxy_connect_signal (DBUS_G_PROXY (obj), "StatusChanged",
          G_CALLBACK (tp_conn_status_change_handler), NULL, NULL);
    }

  if (status != NULL)
    *status = conn_status;

  return obj;
}


TpConn *
tp_conn_new_from_connection (TpConnection *connection,
                             GError **error)
{
  return _tp_conn_new (connection, NULL, error);
}


/* Assume that in practice people will always use the same DBusGConnection. */
static TpDBusDaemon *
_get_dbus_daemon (DBusGConnection *connection)
{
  static TpDBusDaemon *last_daemon = NULL;
  static DBusGConnection *last_connection = NULL;

  if (last_connection == connection &&
      last_daemon != NULL)
    return last_daemon;

  if (last_connection != NULL)
    dbus_g_connection_unref (last_connection);

  last_connection = dbus_g_connection_ref (connection);

  if (last_daemon != NULL)
    g_object_unref (last_daemon);

  last_daemon = tp_dbus_daemon_new (last_connection);

  return last_daemon;
}


TpConn *
tp_conn_new_without_connect (DBusGConnection *connection,
                             const gchar *bus_name,
                             const gchar *object_path,
                             guint *status,
                             GError **error)
{
  TpConnection *conn;
  TpDBusDaemon *dbus_daemon = _get_dbus_daemon (connection);

  conn = tp_connection_new (dbus_daemon, bus_name, object_path, error);

  if (conn == NULL)
    return NULL;

  return _tp_conn_new (conn, status, error);
}


TpConn *
tp_conn_new (DBusGConnection *connection,
             const gchar *bus_name,
             const gchar *object_path)
{
  GError *error = NULL;
  guint status;
  TpConn *obj;

  g_return_val_if_fail (connection != NULL, NULL);
  g_return_val_if_fail (bus_name != NULL, NULL);
  g_return_val_if_fail (object_path, NULL);

  obj = tp_conn_new_without_connect (connection, bus_name, object_path,
      &status, &error);

  if (obj == NULL)
    {
      /* either GetNameOwner, GetStatus or GetInterfaces failed */
      if (error != NULL)
        {
          g_warning ("Failed to create connection for %s %s: %s", bus_name,
              object_path, error->message);
          g_error_free (error);
        }
      else
        {
          g_warning ("Failed to create connection for %s %s: error is NULL",
              bus_name, object_path);
        }

      return NULL;
    }

  if (status != TP_CONNECTION_STATUS_CONNECTED)
    {
      tp_conn_connect_async (DBUS_G_PROXY (obj), _tp_conn_connect_req_handler,
          NULL);
    }

  return obj;
}


TpChan *
tp_conn_new_channel (DBusGConnection *connection,
                     TpConn *tp_conn,
                     const gchar *bus_name,
                     gchar *type,
                     guint handle_type,
                     guint handle,
                     gboolean supress_handler)
{
  TpConnPrivate *priv = TP_CONN_PRIV (tp_conn);
  GError *error = NULL;
  gchar *chan_object_path = NULL;
  TpChannel *channel;

  g_return_val_if_fail (connection, NULL);
  g_return_val_if_fail (TELEPATHY_IS_CONN (tp_conn), NULL);
  g_return_val_if_fail (bus_name, NULL);
  g_return_val_if_fail (type, NULL);

  /* Request a new channel to be created by using the proxy object.
     We also retrieve the object path for it here. */

  if (!tp_conn_request_channel (DBUS_G_PROXY (tp_conn), type, handle_type,
        handle, supress_handler, &chan_object_path, &error))
    {
      _tp_warn_failure ("RequestChannel()", error);

      if (error != NULL)
        g_error_free (error);

      return NULL;
    }

  /* Create the object to represent the channel */

  channel = tp_channel_new (priv->connection, chan_object_path, NULL,
      TP_UNKNOWN_HANDLE_TYPE, 0, &error);

  g_free (chan_object_path);

  if (channel == NULL)
    {
      _tp_warn_failure ("RequestChannel()", error);

      if (error != NULL)
        g_error_free (error);

      return NULL;
    }

  return tp_chan_new_from_channel (channel);
}


void
tp_conn_local_set_interfaces (TpConn *self,
                              gchar **interfaces)
{
  DBusGConnection *connection = tp_get_bus ();
  gchar **temp_ifaces = NULL;
  const gchar *bus_name;
  const gchar *object_path;

  g_return_if_fail (self != NULL);
  g_return_if_fail (connection != NULL);

  bus_name = dbus_g_proxy_get_bus_name (DBUS_G_PROXY (self));
  object_path = dbus_g_proxy_get_path (DBUS_G_PROXY (self));

  if (interfaces == NULL)
    return;

  /* Create and store the proxy objects for the connection interfaces. */
  for (temp_ifaces = interfaces; *temp_ifaces; temp_ifaces++)
    {
      DBusGProxy *if_proxy;
      GQuark key = g_quark_from_string (*temp_ifaces);

      if (key == TP_IFACE_QUARK_PROPERTIES_INTERFACE)
        {
          if_proxy = DBUS_G_PROXY (tp_props_iface_new (connection,
                bus_name, object_path));
        }
      else
        {
          if_proxy = dbus_g_proxy_new_for_name (connection, bus_name,
              object_path, *temp_ifaces);

          if (if_proxy != NULL)
            {
              GData *sig_list =
                TELEPATHY_CONN_GET_CLASS (self)->iface_signal_sigs;
              void (*signature_setter_func) ();

              /* Does the interface have signals? If yes, add their signatures
                 for the interface instance */
              signature_setter_func = g_datalist_id_get_data (&sig_list, key);

              if (signature_setter_func != NULL)
                {
                  signature_setter_func (if_proxy);
                }
            }
        }

       if (if_proxy != NULL)
        {
          g_datalist_id_set_data_full (&(self->interface_list),
              key, if_proxy, g_object_unref);
        }
    }
}

DBusGProxy *
tp_conn_get_interface (TpConn *self,
                       GQuark iface_quark)
{
  DBusGProxy *iface_proxy = NULL;

  g_return_val_if_fail (self != NULL, NULL);
  g_return_val_if_fail (iface_quark != 0, NULL);

  iface_proxy = (DBusGProxy *) g_datalist_id_get_data (
      &(self->interface_list), iface_quark);

  return iface_proxy;
}

void
_tp_conn_connect_req_handler (DBusGProxy *proxy,
                              GError *error,
                              gpointer user_data)
{
  /* The interfaces for the TpConn are set on the StatusChanged
     handler when we get connected. Just print errors (if any)
     here. */

  if (error)
  {
    g_warning ("Could not perform Connect() for the connection, because: %s",
               error->message);
    g_error_free (error);
    return;
  }

}

static gboolean
tp_conn_status_change_handler (DBusGProxy *proxy,
                               guint status,
                               guint reason,
                               gpointer user_data)
{
  gchar **interfaces = NULL;
  GError *error = NULL;
  TpConn *tp_conn = (TpConn *) proxy;

  /* If the connection is up, we can get the list of interfaces */
  /* FIXME: At some point, we should switch to doing this asynchronously */

  if (status == TP_CONNECTION_STATUS_CONNECTED)
    {
      if (!tp_conn_get_interfaces (DBUS_G_PROXY (proxy), &interfaces, &error))
        {
          g_warning ("GetInterfaces failed: %s\n", error->message);
          g_error_free (error);
          return TRUE;
        }

      /* Initialize the interface objects for this TpConn object */

      tp_conn_local_set_interfaces (tp_conn, interfaces);

      g_strfreev (interfaces);

      dbus_g_proxy_disconnect_signal (proxy, "StatusChanged",
          G_CALLBACK (tp_conn_status_change_handler), NULL);
    }

  return TRUE;
}


TpConnection *
tp_conn_dup_connection (TpConn *self)
{
  TpConnPrivate *priv = TP_CONN_PRIV (self);

  return g_object_ref (priv->connection);
}
