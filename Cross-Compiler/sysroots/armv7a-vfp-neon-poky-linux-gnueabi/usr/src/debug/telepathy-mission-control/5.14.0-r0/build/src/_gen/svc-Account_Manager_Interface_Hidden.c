#include "_gen/svc-Account_Manager_Interface_Hidden.h"

#include <telepathy-glib/telepathy-glib.h>
#include "_gen/signals-marshal.h"

static const DBusGObjectInfo _mc_svc_account_manager_interface_hidden_object_info;

struct _McSvcAccountManagerInterfaceHiddenClass {
    GTypeInterface parent_class;
};

enum {
    SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountRemoved,
    SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountValidityChanged,
    N_ACCOUNT_MANAGER_INTERFACE_HIDDEN_SIGNALS
};
static guint account_manager_interface_hidden_signals[N_ACCOUNT_MANAGER_INTERFACE_HIDDEN_SIGNALS] = {0};

static void mc_svc_account_manager_interface_hidden_base_init (gpointer klass);

GType
mc_svc_account_manager_interface_hidden_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
        sizeof (McSvcAccountManagerInterfaceHiddenClass),
        mc_svc_account_manager_interface_hidden_base_init, /* base_init */
        NULL, /* base_finalize */
        NULL, /* class_init */
        NULL, /* class_finalize */
        NULL, /* class_data */
        0,
        0, /* n_preallocs */
        NULL /* instance_init */
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
          "McSvcAccountManagerInterfaceHidden", &info, 0);
    }

  return type;
}

/**
 * mc_svc_account_manager_interface_hidden_emit_hidden_account_removed:
 * @instance: The object implementing this interface
 * @arg_Account: const gchar * (FIXME, generate documentation)
 *
 * Type-safe wrapper around g_signal_emit to emit the
 * HiddenAccountRemoved signal on interface org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1.
 */
void
mc_svc_account_manager_interface_hidden_emit_hidden_account_removed (gpointer instance,
    const gchar *arg_Account)
{
  g_assert (instance != NULL);
  g_assert (G_TYPE_CHECK_INSTANCE_TYPE (instance, MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN));
  g_signal_emit (instance,
      account_manager_interface_hidden_signals[SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountRemoved],
      0,
      arg_Account);
}

/**
 * mc_svc_account_manager_interface_hidden_emit_hidden_account_validity_changed:
 * @instance: The object implementing this interface
 * @arg_Account: const gchar * (FIXME, generate documentation)
 * @arg_Valid: gboolean  (FIXME, generate documentation)
 *
 * Type-safe wrapper around g_signal_emit to emit the
 * HiddenAccountValidityChanged signal on interface org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1.
 */
void
mc_svc_account_manager_interface_hidden_emit_hidden_account_validity_changed (gpointer instance,
    const gchar *arg_Account,
    gboolean arg_Valid)
{
  g_assert (instance != NULL);
  g_assert (G_TYPE_CHECK_INSTANCE_TYPE (instance, MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN));
  g_signal_emit (instance,
      account_manager_interface_hidden_signals[SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountValidityChanged],
      0,
      arg_Account,
      arg_Valid);
}

static inline void
mc_svc_account_manager_interface_hidden_base_init_once (gpointer klass G_GNUC_UNUSED)
{
  static TpDBusPropertiesMixinPropInfo properties[3] = {
      { 0, TP_DBUS_PROPERTIES_MIXIN_FLAG_READ, "ao", 0, NULL, NULL }, /* ValidHiddenAccounts */
      { 0, TP_DBUS_PROPERTIES_MIXIN_FLAG_READ, "ao", 0, NULL, NULL }, /* InvalidHiddenAccounts */
      { 0, 0, NULL, 0, NULL, NULL }
  };
  static TpDBusPropertiesMixinIfaceInfo interface =
      { 0, properties, NULL, NULL };

  dbus_g_object_type_install_info (mc_svc_account_manager_interface_hidden_get_type (),
      &_mc_svc_account_manager_interface_hidden_object_info);

  interface.dbus_interface = g_quark_from_static_string ("org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1");
  properties[0].name = g_quark_from_static_string ("ValidHiddenAccounts");
  properties[0].type = dbus_g_type_get_collection ("GPtrArray", DBUS_TYPE_G_OBJECT_PATH);
  properties[1].name = g_quark_from_static_string ("InvalidHiddenAccounts");
  properties[1].type = dbus_g_type_get_collection ("GPtrArray", DBUS_TYPE_G_OBJECT_PATH);
  tp_svc_interface_set_dbus_properties_info (MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN, &interface);

  /**
   * McSvcAccountManagerInterfaceHidden::hidden-account-removed:
   * @arg_Account: const gchar * (FIXME, generate documentation)
   *
   * The HiddenAccountRemoved D-Bus signal is emitted whenever this GObject signal is.
   */
  account_manager_interface_hidden_signals[SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountRemoved] =
  g_signal_new ("hidden-account-removed",
      G_OBJECT_CLASS_TYPE (klass),
      G_SIGNAL_RUN_LAST|G_SIGNAL_DETAILED,
      0,
      NULL, NULL,
      g_cclosure_marshal_VOID__BOXED,
      G_TYPE_NONE,
      1,
      DBUS_TYPE_G_OBJECT_PATH);

  /**
   * McSvcAccountManagerInterfaceHidden::hidden-account-validity-changed:
   * @arg_Account: const gchar * (FIXME, generate documentation)
   * @arg_Valid: gboolean  (FIXME, generate documentation)
   *
   * The HiddenAccountValidityChanged D-Bus signal is emitted whenever this GObject signal is.
   */
  account_manager_interface_hidden_signals[SIGNAL_ACCOUNT_MANAGER_INTERFACE_HIDDEN_HiddenAccountValidityChanged] =
  g_signal_new ("hidden-account-validity-changed",
      G_OBJECT_CLASS_TYPE (klass),
      G_SIGNAL_RUN_LAST|G_SIGNAL_DETAILED,
      0,
      NULL, NULL,
      _mcd_ext_marshal_VOID__BOXED_BOOLEAN,
      G_TYPE_NONE,
      2,
      DBUS_TYPE_G_OBJECT_PATH,
      G_TYPE_BOOLEAN);

}
static void
mc_svc_account_manager_interface_hidden_base_init (gpointer klass)
{
  static gboolean initialized = FALSE;

  if (!initialized)
    {
      initialized = TRUE;
      mc_svc_account_manager_interface_hidden_base_init_once (klass);
    }
}
static const DBusGMethodInfo _mc_svc_account_manager_interface_hidden_methods[] = {
  { NULL, NULL, 0 }
};

static const DBusGObjectInfo _mc_svc_account_manager_interface_hidden_object_info = {
  0,
  _mc_svc_account_manager_interface_hidden_methods,
  0,
"\0",
"org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1\0HiddenAccountRemoved\0org.freedesktop.Telepathy.AccountManager.Interface.Hidden.DRAFT1\0HiddenAccountValidityChanged\0\0",
"\0\0",
};


