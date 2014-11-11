/* tp-chan.h
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

#ifndef TP_CHAN_H
#define TP_CHAN_H

#ifndef DBUS_API_SUBJECT_TO_CHANGE
#define DBUS_API_SUBJECT_TO_CHANGE
#endif

#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>
#include <telepathy-glib/channel.h>


#include "tp-chan-gen.h"
#include "tp-interfaces.h"
#include "tp-chan-signals-marshal.h"
#include "tp-ifaces-signals-marshal.h"
#include "tp-chan-ifaces-signal-setters.h"


#define TELEPATHY_CHAN_TYPE (tp_chan_get_type ())

#define TELEPATHY_CHAN(obj) (G_TYPE_CHECK_INSTANCE_CAST \
    ((obj), TELEPATHY_CHAN_TYPE, TpChan))

#define TELEPATHY_CHAN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST \
    ((klass), TELEPATHY_CHAN_TYPE, TpChanClass))

#define TELEPATHY_IS_CHAN(obj) (G_TYPE_CHECK_INSTANCE_TYPE \
    ((obj), TELEPATHY_CHAN_TYPE))

#define TELEPATHY_IS_CHAN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
    ((klass), TELEPATHY_CHAN_TYPE))

#define TELEPATHY_CHAN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS \
    ((obj), TELEPATHY_CHAN_TYPE, TpChanClass))

/* For backwards compatibility only. */

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED

#define TELEPATHY_CHAN_IFACE_QUARK \
  TP_IFACE_QUARK_CHANNEL
#define TELEPATHY_CHAN_IFACE_CONTACTLIST_QUARK \
  TP_IFACE_QUARK_CHANNEL_TYPE_CONTACT_LIST
#define TELEPATHY_CHAN_IFACE_STREAMED_QUARK \
  TP_IFACE_QUARK_CHANNEL_TYPE_STREAMED_MEDIA
#define TELEPATHY_CHAN_IFACE_ROOMLIST_QUARK \
  TP_IFACE_QUARK_CHANNEL_TYPE_ROOM_LIST
#define TELEPATHY_CHAN_IFACE_TEXT_QUARK \
  TP_IFACE_QUARK_CHANNEL_TYPE_TEXT
#define TELEPATHY_CHAN_IFACE_DTMF_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_DTMF
#define TELEPATHY_CHAN_IFACE_CHAT_STATE_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_CHAT_STATE
#define TELEPATHY_CHAN_IFACE_GROUP_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_GROUP
#define TELEPATHY_CHAN_IFACE_HOLD_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_HOLD
#define TELEPATHY_CHAN_IFACE_PASSWORD_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_PASSWORD
#define TELEPATHY_CHAN_IFACE_TRANSFER_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_TRANSFER
#define TELEPATHY_CHAN_IFACE_MEDIA_SIGNALLING_QUARK \
  TP_IFACE_QUARK_CHANNEL_INTERFACE_MEDIA_SIGNALLING
#define TELEPATHY_CHAN_IFACE_TUBES_QUARK \
  TP_IFACE_QUARK_CHANNEL_TYPE_TUBES

#endif

typedef struct _tp_chan TpChan;
typedef struct _tp_chanclass TpChanClass;

struct _tp_chan
{
  DBusGProxy parent;
  gchar *type;
  guint handle_type;
  guint handle;
  GData *interface_list;
  gboolean first_run;
};

struct _tp_chanclass
{
  DBusGProxyClass parent_class;
  GData *iface_signal_sigs;
};

GType tp_chan_get_type (void);

/* Actual function definitions */


/*
 * Creates a new channel object.
 *
 * @param connection: The D-BUS connection for this channel.
 * @param bus_name: The D-BUS bus name for this channel.
 * @param object_name: The name of the D-BUS path for this channel.
 * @param type: The type string for this channel.
 * @param handle_type: The type of this channel.
 * @param handle: The handle of this channel, will be filled by this call.
 * @return A new TpChan (channel) object, or NULL if unsuccesfull
 */

TpChan *tp_chan_new (DBusGConnection *connection, const gchar *bus_name,
    const gchar *object_path, const gchar *type,
    guint handle_type, guint handle);


/*
 * Retrieve or create a telepathy-glib TpChannel object for this channel.
 *
 * The returned TpChannel is not guaranteed to be ready (use the
 * channel-ready property, the notify::channel-ready signal, or
 * tp_channel_run_until_ready()).
 *
 * This function exists to aid migration from libtelepathy to telepathy-glib.
 * Available since 0.3.2.
 *
 * @param self: the libtelepathy channel object
 * @param connection: a telepathy-glib connection object, to create the
 *  TpChannel if necessary
 * @param error: if not NULL, used to return any error encountered while
 *  creating the channel object
 * @return a new reference to a TpChannel, which must be unreffed by the
 *  caller, or NULL on error
 */
TpChannel *tp_chan_dup_channel (TpChan *self, TpConnection *connection,
    GError **error);


/*
 * Create a new channel object from a telepathy-glib TpChannel.
 *
 * The TpChannel must not have already been invalidated.
 *
 * If the TpChannel is not yet "ready" (as indicated by the channel-ready
 * property), the TpChan's type, handle_type and handle members might be
 * wrong. If these are significant to you, wait for the TpChannel to be ready
 * first, e.g. by calling tp_channel_run_until_ready().
 *
 * This function exists to aid migration from libtelepathy to telepathy-glib.
 * Available since 0.3.2.
 *
 * @param channel: the channel
 * @return A new TpChan object, or NULL if unsuccessful
 */
TpChan *tp_chan_new_from_channel (TpChannel *channel);


/* Create and store the D-BUS proxy objects for the interfaces provided
 * by this channel. Expects data provided by the GetInterfaces method.
 *
 * @param self: The channel object whose interfaces will be stored.
 * @param interfaces: The array of strings containing the interface names
 *
 */


void tp_chan_local_set_interfaces (TpChan *self, gchar **interfaces);


/*
 * This function checks whether the channel has the specified
 * interface and returns a proxy object that can be used to call
 * its methods, if it exists. The supported interfaces are listed
 * in the beginning of this header as macros.
 *
 * @param self The channel object that is queried for the interface
 *             proxy object
 * @param iface_quark GQuark corresponding to the interface name
 *        string.
 * @return A DBusGProxy object for the interface, or NULL if not found
 */

DBusGProxy *tp_chan_get_interface (TpChan *self, GQuark iface_quark);

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED
GQuark tp_get_chan_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_contactlist_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_streamed_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_roomlist_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_text_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_dtmf_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_chat_state_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_group_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_hold_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_password_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_transfer_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_media_signalling_interface (void) G_GNUC_DEPRECATED;
GQuark tp_get_chan_tubes_interface (void) G_GNUC_DEPRECATED;
#endif

#endif

