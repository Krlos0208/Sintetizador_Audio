/* tp-conn-ifaces-signal-setters.c
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

#include "tp-conn-ifaces-signal-setters.h"

#include "_gen/add-signals.h"

void
tp_conn_set_aliasing_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_ALIASING (proxy);
}

void
tp_conn_set_avatars_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_AVATARS (proxy);
}

void
tp_conn_set_capabilities_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_CAPABILITIES (proxy);
}

void
tp_conn_set_contactinfo_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_CONTACT_INFO (proxy);
}
void
tp_conn_set_forwarding_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_FORWARDING (proxy);
}
void
tp_conn_set_presence_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_PRESENCE (proxy);
}
void
tp_conn_set_privacy_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_PRIVACY (proxy);
}
void
tp_conn_set_renaming_signatures (DBusGProxy *proxy)
{
  ADD_SIGNALS_FOR_CONNECTION_INTERFACE_RENAMING (proxy);
}
