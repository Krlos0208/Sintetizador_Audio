/* tp-chan-ifaces-signal-setters.c
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

#include "tp-chan-ifaces-signal-setters.h"

#include "_gen/add-signals.h"

void
tp_chan_set_streamedmedia_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_TYPE_STREAMED_MEDIA (proxy);
}

void
tp_chan_set_roomlist_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_TYPE_ROOM_LIST (proxy);
}

void
tp_chan_set_text_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_TYPE_TEXT (proxy);
}

void
tp_chan_set_chat_state_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_CHAT_STATE (proxy);
}

void
tp_chan_set_dtmf_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_DTMF (proxy);
}

void
tp_chan_set_group_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_GROUP (proxy);
}

void
tp_chan_set_hold_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_HOLD (proxy);
}

void
tp_chan_set_password_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_PASSWORD (proxy);
}

void
tp_chan_set_media_signalling_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_INTERFACE_MEDIA_SIGNALLING (proxy);
}

void
tp_chan_set_tubes_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CHANNEL_TYPE_TUBES (proxy);
}
