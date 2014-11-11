/* Generated from: Telepathy D-Bus Interface Specification version 0.17.0

Copyright (C) 2005, 2006, 2007 Collabora Limited
Copyright (C) 2005, 2006, 2007 Nokia Corporation
Copyright (C) 2006 INdT


This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

 */

GQuark
tp_iface_quark_connection_interface_contact_info (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Connection.Interface.ContactInfo");
    }

  return quark;
}

GQuark
tp_iface_quark_connection_interface_forwarding (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Connection.Interface.Forwarding");
    }

  return quark;
}

GQuark
tp_iface_quark_connection_interface_privacy (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Connection.Interface.Privacy");
    }

  return quark;
}

GQuark
tp_iface_quark_connection_interface_renaming (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Connection.Interface.Renaming");
    }

  return quark;
}

GQuark
tp_iface_quark_channel_interface_hold (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Channel.Interface.Hold");
    }

  return quark;
}

GQuark
tp_iface_quark_channel_interface_transfer (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Channel.Interface.Transfer");
    }

  return quark;
}

