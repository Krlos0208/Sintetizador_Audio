/* tp-chan.c
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

#include "tp-chan.h"

#include <string.h>

#include "tp-props-iface.h"
#include "tp-helpers.h"
#include "internal.h"
#include "_gen/add-signals.h"


G_DEFINE_TYPE (TpChan, tp_chan, DBUS_TYPE_G_PROXY);

typedef struct {
    TpChannel *channel;
} TpChanPrivate;

#define TP_CHAN_PRIV(o) \
    (G_TYPE_INSTANCE_GET_PRIVATE (o, TELEPATHY_CHAN_TYPE, TpChanPrivate))


/* We initialize the list of signatures here, so that we can use
 * it to add them for new interface instances later.*/

/* FIXME: This should be replaced by a more automatic way of doing
 * this. The reason for using a set of function pointers is that there is no
 * apparent cleaner way of doing this, unless DBusGProxy gains a non-varargs
 * version of dbus_g_proxy_add_signal...
 */

static void
_tp_chan_init_interface_signal_signatures (GData **signal_sigs)
{
  g_datalist_init (signal_sigs);

  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CHANNEL_TYPE_STREAMED_MEDIA,
      tp_chan_set_streamedmedia_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_TYPE_ROOM_LIST,
      tp_chan_set_roomlist_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_TYPE_TEXT,
      tp_chan_set_text_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CHANNEL_INTERFACE_CHAT_STATE,
      tp_chan_set_chat_state_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_INTERFACE_DTMF,
      tp_chan_set_dtmf_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_INTERFACE_GROUP,
      tp_chan_set_group_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_INTERFACE_HOLD,
      tp_chan_set_hold_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CHANNEL_INTERFACE_PASSWORD,
      tp_chan_set_password_signatures);
  g_datalist_id_set_data (signal_sigs,
      TP_IFACE_QUARK_CHANNEL_INTERFACE_MEDIA_SIGNALLING,
      tp_chan_set_media_signalling_signatures);
  g_datalist_id_set_data (signal_sigs, TP_IFACE_QUARK_CHANNEL_TYPE_TUBES,
      tp_chan_set_tubes_signatures);
}

static void
tp_chan_init (TpChan *self)
{
  self->type = NULL;
  self->first_run = TRUE;
}


static void
_tp_chan_lost_channel (TpChannel *channel,
                       guint domain,
                       gint code,
                       gchar *message,
                       TpChan *self)
{
  TpChanPrivate *priv = TP_CHAN_PRIV (self);

  if (priv->channel != NULL)
    {
      g_object_unref (priv->channel);
      priv->channel = NULL;
    }
}


static void
tp_chan_dispose (GObject *obj)
{
  TpChan *self = TELEPATHY_CHAN (obj);

  if (self->first_run)
    {
      TpChanPrivate *priv = TP_CHAN_PRIV (self);

      self->first_run = FALSE;
      g_datalist_clear (&(self->interface_list));

      if (priv->channel != NULL)
        {
          g_signal_handlers_disconnect_by_func (priv->channel,
              _tp_chan_lost_channel, self);
          g_object_unref (priv->channel);
          priv->channel = NULL;
        }
    }

  G_OBJECT_CLASS (tp_chan_parent_class)->dispose (obj);
}


static void
tp_chan_finalize (GObject *obj)
{
  TpChan *self = TELEPATHY_CHAN (obj);

  if (self->type)
    {
      g_free (self->type);
    }

  G_OBJECT_CLASS (tp_chan_parent_class)->finalize (obj);
}


static void
tp_chan_class_init (TpChanClass *klass)
{
  GObjectClass *obj = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (TpChanPrivate));

  obj->dispose = tp_chan_dispose;
  obj->finalize = tp_chan_finalize;

  _tp_register_marshallers ();
  _tp_chan_init_interface_signal_signatures (&(klass->iface_signal_sigs));
}


/* Public functions begin */

GQuark
tp_get_chan_interface (void)
{
  return tp_iface_quark_channel ();
}

GQuark
tp_get_chan_contactlist_interface (void)
{
  return tp_iface_quark_channel_type_contact_list ();
}


GQuark
tp_get_chan_streamed_interface (void)
{
  return tp_iface_quark_channel_type_streamed_media ();
}


GQuark
tp_get_chan_roomlist_interface (void)
{
  return tp_iface_quark_channel_type_room_list ();
}

GQuark
tp_get_chan_text_interface (void)
{
  return tp_iface_quark_channel_type_text ();
}

GQuark
tp_get_chan_tubes_interface (void)
{
  return tp_iface_quark_channel_type_tubes ();
}

GQuark
tp_get_chan_chat_state_interface (void)
{
  return tp_iface_quark_channel_interface_chat_state ();
}

GQuark
tp_get_chan_dtmf_interface (void)
{
  return tp_iface_quark_channel_interface_dtmf ();
}

GQuark
tp_get_chan_group_interface (void)
{
  return tp_iface_quark_channel_interface_group ();
}

GQuark
tp_get_chan_hold_interface (void)
{
  return tp_iface_quark_channel_interface_hold ();
}

GQuark
tp_get_chan_password_interface (void)
{
  return tp_iface_quark_channel_interface_password ();
}

GQuark
tp_get_chan_transfer_interface (void)
{
  return tp_iface_quark_channel_interface_transfer ();
}

GQuark
tp_get_chan_media_signalling_interface (void)
{
  return tp_iface_quark_channel_interface_media_signalling ();
}


static TpChannel *
_tp_chan_set_channel (TpChan *self,
                      TpChannel *channel)
{
  TpChanPrivate *priv = TP_CHAN_PRIV (self);
  TpProxy *channel_as_proxy = TP_PROXY (channel);

  g_return_val_if_fail (channel_as_proxy->invalidated == NULL, NULL);
  g_assert (priv->channel == NULL);
  priv->channel = g_object_ref (channel);

  g_signal_connect (channel, "invalidated",
      G_CALLBACK (_tp_chan_lost_channel), self);

  return channel;
}


static void
_tp_chan_local_set_interface (TpChan *self,
                              GQuark key,
                              DBusGProxy *proxy)
{
  GData **sig_list = &(TELEPATHY_CHAN_GET_CLASS (self)->iface_signal_sigs);
  void (*signature_setter_func) (DBusGProxy *proxy);

  if (proxy == NULL)
    {
      proxy = dbus_g_proxy_new_from_proxy ((DBusGProxy *) self,
          g_quark_to_string (key),
          NULL);

      if (proxy == NULL)
        {
          g_critical ("dbus_g_proxy_new_from_proxy (%p, %s, NULL) failed",
              self, g_quark_to_string (key));
          return;
        }
    }

  signature_setter_func = g_datalist_id_get_data (sig_list, key);

  if (signature_setter_func != NULL)
    (*signature_setter_func) (proxy);

  g_datalist_id_set_data_full (&self->interface_list, key, proxy,
      g_object_unref);
}


static void
_tp_chan_retrieve_type (TpChan *self)
{
  gchar *chan_type = NULL;
  GError *error = NULL;

  if (!tp_chan_get_channel_type (DBUS_G_PROXY (self), &chan_type, &error))
    {
      _tp_warn_failure ("GetChannelType", error);

      if (error != NULL)
        g_error_free (error);
    }
  else
    {
      _tp_chan_local_set_interface (self, g_quark_from_string (chan_type),
          NULL);
      g_free (chan_type);
    }
}


static void
_tp_chan_local_set_interfaces (TpChan *self,
                               gchar **interfaces)
{
  gchar **temp_ifaces;

  g_return_if_fail (self != NULL);

  if (interfaces == NULL)
    return;

  /* Create and store proxy objects corresponding to the
     interfaces */

  for (temp_ifaces = interfaces; *temp_ifaces != NULL; temp_ifaces++)
    {
      GQuark key = g_quark_from_string (*temp_ifaces);

      if (key == TP_IFACE_QUARK_PROPERTIES_INTERFACE)
        {
          DBusGConnection *connection;
          gchar *name, *path;

          g_object_get (self,
              "connection", &connection,
              "name", &name,
              "path", &path,
              NULL);

          _tp_chan_local_set_interface (self, key,
              DBUS_G_PROXY (tp_props_iface_new (connection, name, path)));

          g_free (name);
          g_free (path);
          dbus_g_connection_unref (connection);
        }
      else
        {
          _tp_chan_local_set_interface (self, key, NULL);
        }
    }
}


static TpChan *
_tp_chan_new (TpChannel *maybe_channel,
              DBusGConnection *connection,
              const gchar *bus_name,
              const gchar *object_path,
              const gchar *type,
              guint handle_type,
              guint handle,
              gchar **interfaces)
{
  GError *error = NULL;
  gchar *unique_name = NULL;
  TpChan *chan;

  g_return_val_if_fail (connection != NULL, NULL);
  g_return_val_if_fail (bus_name != NULL, NULL);
  g_return_val_if_fail (object_path != NULL, NULL);

  if (bus_name[0] != ':')
    {
      if (!dbus_g_proxy_call (tp_get_bus_proxy (), "GetNameOwner", &error,
            G_TYPE_STRING, bus_name, G_TYPE_INVALID,
            G_TYPE_STRING, &unique_name, G_TYPE_INVALID))
        {
          _tp_warn_failure ("tp_chan_new: getting unique name", error);

          if (error != NULL)
            g_error_free (error);

          return NULL;
        }

      bus_name = unique_name;
    }

  /* Create the channel object */
  chan = g_object_new (TELEPATHY_CHAN_TYPE,
            "name", bus_name,
            "path", object_path,
            "interface", TP_IFACE_CHANNEL,
            "connection", connection,
            NULL);

  g_free (unique_name);

  if (maybe_channel != NULL)
      _tp_chan_set_channel (chan, maybe_channel);

  ADD_SIGNALS_FOR_CHANNEL (DBUS_G_PROXY (chan));

  g_datalist_init (&(chan->interface_list));

  if (interfaces != NULL)
    {
      _tp_chan_local_set_interfaces (chan, interfaces);
    }
  else
    {
      /* Store interface information for the channel */
      if (tp_chan_get_interfaces (DBUS_G_PROXY (chan), &interfaces, &error))
        {
          _tp_chan_local_set_interfaces (chan, interfaces);

          /* Free the strings used for interface object creation */
          g_strfreev (interfaces);
          interfaces = NULL;
        }
      else
        {
          _tp_warn_failure ("GetInterfaces for channel", error);

          if (error != NULL)
            g_error_free (error);
        }
    }

  if (type != NULL)
    {
      _tp_chan_local_set_interface (chan, g_quark_from_string (type), NULL);
    }
  else
    {
      _tp_chan_retrieve_type (chan);
    }

  /* Store necessary information for this object */
  chan->type = g_strdup (type);
  chan->handle_type = handle_type;
  chan->handle = handle;

  return chan;
}


TpChan *
tp_chan_new_from_channel (TpChannel *channel)
{
  TpChan *self;
  gboolean channel_ready;
  DBusGConnection *dbus_connection;
  gchar *bus_name, *object_path;

  g_return_val_if_fail (channel != NULL, NULL);

  g_object_get (channel,
      "dbus-connection", &dbus_connection,
      "channel-ready", &channel_ready,
      "bus-name", &bus_name,
      "object-path", &object_path,
      NULL);

  g_return_val_if_fail (dbus_connection != NULL, NULL);
  g_return_val_if_fail (bus_name != NULL, NULL);
  g_return_val_if_fail (object_path != NULL, NULL);

  if (channel_ready)
    {
      gchar *channel_type;
      gchar **interfaces;
      guint handle_type, handle;

      g_object_get (channel,
          "channel-type", &channel_type,
          "handle-type", &handle_type,
          "handle", &handle,
          "interfaces", &interfaces,
          NULL);

      self = _tp_chan_new (channel, dbus_connection, bus_name, object_path,
          channel_type, handle_type, handle, interfaces);

      g_free (channel_type);
      g_strfreev (interfaces);
    }
  else
    {
      self = _tp_chan_new (channel, dbus_connection, bus_name, object_path,
          NULL, 0, 0, NULL);
    }

  g_free (object_path);
  g_free (bus_name);

  if (dbus_connection != NULL)
    dbus_g_connection_unref (dbus_connection);

  return self;
}


TpChan *
tp_chan_new (DBusGConnection *connection,
             const gchar *bus_name,
             const gchar *object_path,
             const gchar *type,
             guint handle_type,
             guint handle)
{
  return _tp_chan_new (NULL, connection, bus_name, object_path,
      type, handle_type, handle, NULL);
}


TpChannel *
tp_chan_dup_channel (TpChan *self,
                     TpConnection *connection,
                     GError **error)
{
  TpChanPrivate *priv = TP_CHAN_PRIV (self);

  if (priv->channel != NULL)
    return g_object_ref (priv->channel);

  return _tp_chan_set_channel (self, tp_channel_new (connection,
      dbus_g_proxy_get_path ((DBusGProxy *) self), NULL,
      TP_UNKNOWN_HANDLE_TYPE, 0, error));
}


/* this is public API. I'm not sure why, but we'd better keep it behaving
 * the same... */
void
tp_chan_local_set_interfaces (TpChan *self,
                              gchar **interfaces)
{
  _tp_chan_local_set_interfaces (self, interfaces);
  _tp_chan_retrieve_type (self);
}

DBusGProxy *
tp_chan_get_interface (TpChan *self,
                       GQuark iface_quark)
{
  DBusGProxy *iface_proxy = NULL;

  g_return_val_if_fail (self != NULL, NULL);
  g_return_val_if_fail (iface_quark != 0, NULL);

  iface_proxy = (DBusGProxy *) g_datalist_id_get_data (
      &(self->interface_list), iface_quark);

  return iface_proxy;
}

