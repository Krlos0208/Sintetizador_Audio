/* tp-connmgr.c
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

#include "tp-connmgr.h"

#include "tp-conn.h"
#include "tp-helpers.h"
#include "internal.h"
#include "_gen/add-signals.h"


static GObjectClass *parent_class = NULL;


static void
tp_connmgr_dispose (GObject *obj)
{
  TpConnMgr *self = TELEPATHY_CONNMGR (obj);

  if (self->first_run)
    {
      self->first_run = FALSE;
    }

  G_OBJECT_CLASS (parent_class)->dispose (obj);
}


static void
tp_connmgr_init (GTypeInstance *instance, gpointer g_class)
{
  TpConnMgr *self = TELEPATHY_CONNMGR (instance);

  self->first_run = TRUE;
}


static void
tp_connmgr_class_init (TpConnMgrClass *klass)
{
  GObjectClass *obj = G_OBJECT_CLASS (klass);
  parent_class = g_type_class_peek_parent (klass);

  obj->dispose = tp_connmgr_dispose;

  _tp_register_marshallers ();
}


GType
tp_connmgr_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
          sizeof (TpConnMgrClass),
          NULL,
          NULL,
          (GClassInitFunc) tp_connmgr_class_init,
          NULL,
          NULL,
          sizeof (TpConnMgr),
          0,
          (GInstanceInitFunc) tp_connmgr_init
      };

      type = g_type_register_static (DBUS_TYPE_G_PROXY,
          "TpConnMgr", &info, 0);
    }

  return type;
}


TpConnMgr *
tp_connmgr_new (DBusGConnection *connection,
                const char *bus_name,
                const char *object_path,
                const char *interface_name)
{
  TpConnMgr *obj;

  g_return_val_if_fail (connection != NULL, NULL);
  g_return_val_if_fail (bus_name != NULL, NULL);
  g_return_val_if_fail (object_path, NULL);
  g_return_val_if_fail (interface_name, NULL);

  obj = g_object_new (TELEPATHY_CONNMGR_TYPE,
      "name", bus_name,
      "path", object_path,
      "interface", interface_name,
      "connection", connection,
      NULL);

  ADD_SIGNALS_FOR_CONNECTION_MANAGER (DBUS_G_PROXY (obj));

  return obj;
}


TpConn *
tp_connmgr_new_connection (TpConnMgr *self,
                           GHashTable *connection_parameters,
                           gchar *protocol)
{
  GError *error = NULL;
  guint status;
  TpConn *conn;

  g_return_val_if_fail (self != NULL, NULL);
  g_return_val_if_fail (connection_parameters != NULL, NULL);
  g_return_val_if_fail (protocol != NULL, NULL);

  conn = tp_connmgr_new_connection_without_connect (self,
      connection_parameters, protocol, &status, &error);

  if (conn == NULL)
    {
      /* either GetNameOwner, GetStatus or GetInterfaces failed */
      g_warning ("Failed to create connection: %s", error->message);
      g_error_free (error);
    }

  if (status != TP_CONNECTION_STATUS_CONNECTED)
    {
      tp_conn_connect_async (DBUS_G_PROXY (conn), _tp_conn_connect_req_handler,
          NULL);
    }

  return conn;
}


TpConn *
tp_connmgr_new_connection_without_connect (TpConnMgr *self,
                                           GHashTable *connection_parameters,
                                           gchar *protocol,
                                           guint *status,
                                           GError **error)
{
  TpConn *tp_conn_obj;
  DBusGConnection *connection = tp_get_bus ();
  gchar *bus_name = NULL, *object_path = NULL;

  g_return_val_if_fail (TELEPATHY_IS_CONNMGR (self), NULL);
  g_return_val_if_fail (connection_parameters != NULL, NULL);

  if (!tp_connmgr_request_connection (DBUS_G_PROXY (self),
        protocol, connection_parameters, &bus_name, &object_path, error))
    {
      return NULL;
    }

  tp_conn_obj = tp_conn_new_without_connect (connection, bus_name,
      object_path, status, error);

  g_free (bus_name);
  g_free (object_path);

  return tp_conn_obj;
}
