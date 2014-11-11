/* tp-conn.h
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


#ifndef TP_CONN_H
#define TP_CONN_H

#ifndef DBUS_API_SUBJECT_TO_CHANGE
#define DBUS_API_SUBJECT_TO_CHANGE
#endif

#include <dbus/dbus-glib.h>
#include <telepathy-glib/connection.h>

#include "tp-conn-gen.h"
#include "tp-conn-iface-forwarding-gen.h"
#include "tp-chan.h"
#include "tp-conn-signals-marshal.h"
#include "tp-ifaces-signals-marshal.h"
#include "tp-conn-ifaces-signal-setters.h"
#include "tp-interfaces.h"
#include "tp-constants.h"

#define DBUS_TYPE_G_ARRAY_OF_STRUCTS dbus_g_type_get_collection ("GPtrArray", G_TYPE_VALUE_ARRAY);

#define TELEPATHY_CONN_TYPE  (tp_conn_get_type ())

#define TELEPATHY_CONN(obj) (G_TYPE_CHECK_INSTANCE_CAST \
    ((obj), TELEPATHY_CONN_TYPE, TpConn))

#define TELEPATHY_CONN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST \
    ((klass), TELEPATHY_CONN_TYPE, TpConnClass))

#define TELEPATHY_IS_CONN(obj) (G_TYPE_CHECK_INSTANCE_TYPE \
    ((obj), TELEPATHY_CONN_TYPE))

#define TELEPATHY_IS_CONN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
    ((klass), TELEPATHY_CONN_TYPE))

#define TELEPATHY_CONN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS \
    ((obj), TELEPATHY_CONN_TYPE, TpConnClass))

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED

/* For backwards compatibility only. Use TP_IFACE_QUARK_* in new code */
#define TELEPATHY_CONN_IFACE_QUARK \
  TP_IFACE_QUARK_CONNECTION
#define TELEPATHY_CONN_IFACE_ALIASING_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_ALIASING
#define TELEPATHY_CONN_IFACE_AVATARS_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_AVATARS
#define TELEPATHY_CONN_IFACE_CAPABILITIES_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_CAPABILITIES
#define TELEPATHY_CONN_IFACE_CONTACTINFO_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_CONTACT_INFO
#define TELEPATHY_CONN_IFACE_FORWARDING_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_FORWARDING
#define TELEPATHY_CONN_IFACE_PRESENCE_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_PRESENCE
#define TELEPATHY_CONN_IFACE_PRIVACY_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_PRIVACY
#define TELEPATHY_CONN_IFACE_RENAMING_QUARK \
  TP_IFACE_QUARK_CONNECTION_INTERFACE_RENAMING

#endif

typedef struct _tp_conn TpConn;
typedef struct _tp_connclass TpConnClass;

struct _tp_conn
{
  DBusGProxy parent;
  GData *interface_list;
  gboolean first_run;
};


struct _tp_connclass
{
  DBusGProxyClass parent_class;
  GData *iface_signal_sigs;
};


GType tp_conn_get_type (void);

/* Actual function definitions */

/*
 * Create a new TpConn (Connection) object and try to connect asynchronously.
 *
 * @param connection The D-BUS connection
 * @param name: The D-BUS service name for the connection object
 * @param path_name: The D-BUS path name for the connection object
 * @param interface_name: The D-BUS interface name for the connection object
 * @return A new TpConn connection object, or NULL if unsuccesful.
 *
 * @deprecated since 0.3.0. Use tp_conn_new_without_connect() instead
 */

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED
TpConn *tp_conn_new (DBusGConnection *connection, const char *bus_name,
    const char *object_path) G_GNUC_DEPRECATED;
#endif

/* Create a new #TpConn from a #TpConnection.
 * It will be ready for use if and only if the #TpConnection is; consider
 * using tp_connection_run_until_ready() first.
 *
 * @param connection: A telepathy-glib #TpConnection
 * @param error: Used to return error if GetStatus() fails
 * @return A new TpConn object, or NULL if GetStatus() fails
 */
TpConn *tp_conn_new_from_connection (TpConnection *connection, GError **error);

/*
 * Retrieve or create a telepathy-glib TpConnection object for this connection.
 *
 * The returned TpConnection is not guaranteed to be ready (use the
 * connection-ready property, the notify::connection-ready signal, or
 * tp_connection_run_until_ready()).
 *
 * This function exists to aid migration from libtelepathy to telepathy-glib.
 * Available since 0.3.2.
 *
 * @param self: the libtelepathy connection object
 * @return a new reference to a TpConnection, which must be unreffed by the
 *  caller
 */
TpConnection *tp_conn_dup_connection (TpConn *self);

/* Create a new #TpConn and connect signal handlers, but do not try to connect
 * asynchronously.
 *
 * If TP_CONNECTION_STATUS_CONNECTED is written through @status, the new
 * connection is connected, and has its interfaces set up and is ready for use.
 * Otherwise, the caller is responsible for calling Connect and waiting for
 * the connection attempt to either succeed or fail.
 *
 * @param connection: A bus connection
 * @param bus_name: The bus name of the CM
 * @param object_path: The object path at that bus name for which a proxy is
 *                     required
 * @param status: Used to return the connection's status at the time we found
 *                it
 * @param error: Used to return the error if NULL is returned
 *
 * @return A new TpConn object, or NULL if GetNameOwner, GetStatus or
 *         GetInterfaces fails
 */
TpConn *tp_conn_new_without_connect (DBusGConnection *connection,
    const char *bus_name, const char *object_path,
    guint *status, GError **error);

/* Create a TpChan channel object for this connection. Also initialises
 * the proxy object that is used for the actual method calls.
 *
 * @param connection: The DBusGConnection for the channel
 * @param tpconn:  The Connection object for which the channel is done
 * @param bus_name:  The D-Bus interface name for the channel
 * @param type: The channel type string
 * @param handle_type: The type of the channel handle
 * @param handle: The channel handle value is set and stored here after
 * @param         the call returns.
 * @param supress_handler: if TRUE, indicates that no handler needs to be
 *                         launched
 *
 * @return A new TpChan (channel) object
 */

TpChan *tp_conn_new_channel (DBusGConnection *connection, TpConn *tpconn,
    const gchar *bus_name, gchar *type, guint handle_type, guint handle,
    gboolean supress_handler);


/* Creates the proxy objects for the channel interfaces. GetInterfaces
 * method should be called before this to acquire the interface name
 * list.
 *
 * @param self: The connection object
 * @param interfaces: An array of the interface name strings
 */

void tp_conn_local_set_interfaces (TpConn *self, gchar **interfaces);


/*
 * This function checks whether the Connection has the specified
 * interface and returns a proxy object that can be used to call
 * its methods, if it exists. The supported interfaces are listed
 * in the beginning of this header as macros.
 *
 * @param self The connection object that is queried for the
 *             interface proxy object
 * @param iface_quark GQuark corresponding to the interface name
 *        string.
 * @return A DBusGProxy object for the interface, or NULL if not found
 */

DBusGProxy *tp_conn_get_interface (TpConn *self, GQuark iface_quark);

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED
GQuark tp_get_conn_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_aliasing_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_avatars_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_capabilities_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_contactinfo_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_forwarding_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_presence_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_privacy_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_conn_renaming_interface (void) G_GNUC_DEPRECATED;
#endif

#endif
