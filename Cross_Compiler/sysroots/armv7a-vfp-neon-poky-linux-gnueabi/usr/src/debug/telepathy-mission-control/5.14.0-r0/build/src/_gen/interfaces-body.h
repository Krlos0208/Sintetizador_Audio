/* Generated from: 

Copyright (C) 2008 Nokia Corporation


 */

GQuark
mc_iface_quark_connection_manager_interface_account_storage (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.ConnectionManager.Interface.AccountStorage.DRAFT");
    }

  return quark;
}

GQuark
mc_iface_quark_account_interface_conditions (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("com.nokia.Account.Interface.Conditions");
    }

  return quark;
}

GQuark
mc_iface_quark_account_interface_external_password_storage (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Account.Interface.ExternalPasswordStorage.DRAFT");
    }

  return quark;
}

GQuark
mc_iface_quark_account_interface_hidden (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.Account.Interface.Hidden.DRAFT1");
    }

  return quark;
}

GQuark
mc_iface_quark_account_manager_interface_hidden (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1");
    }

  return quark;
}

GQuark
mc_iface_quark_channel_dispatcher_interface_messages_draft (void)
{
  static GQuark quark = 0;

  if (G_UNLIKELY (quark == 0))
    {
      quark = g_quark_from_static_string ("org.freedesktop.Telepathy.ChannelDispatcher.Interface.Messages.DRAFT");
    }

  return quark;
}

