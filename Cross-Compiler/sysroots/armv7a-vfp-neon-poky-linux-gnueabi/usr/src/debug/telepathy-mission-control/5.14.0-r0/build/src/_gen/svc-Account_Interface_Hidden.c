#include "_gen/svc-Account_Interface_Hidden.h"

#include <telepathy-glib/telepathy-glib.h>
#include "_gen/signals-marshal.h"

static const DBusGObjectInfo _mc_svc_account_interface_hidden_object_info;

struct _McSvcAccountInterfaceHiddenClass {
    GTypeInterface parent_class;
};

static void mc_svc_account_interface_hidden_base_init (gpointer klass);

GType
mc_svc_account_interface_hidden_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
        sizeof (McSvcAccountInterfaceHiddenClass),
        mc_svc_account_interface_hidden_base_init, /* base_init */
        NULL, /* base_finalize */
        NULL, /* class_init */
        NULL, /* class_finalize */
        NULL, /* class_data */
        0,
        0, /* n_preallocs */
        NULL /* instance_init */
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
          "McSvcAccountInterfaceHidden", &info, 0);
    }

  return type;
}

static inline void
mc_svc_account_interface_hidden_base_init_once (gpointer klass G_GNUC_UNUSED)
{
  static TpDBusPropertiesMixinPropInfo properties[2] = {
      { 0, TP_DBUS_PROPERTIES_MIXIN_FLAG_READ, "b", 0, NULL, NULL }, /* Hidden */
      { 0, 0, NULL, 0, NULL, NULL }
  };
  static TpDBusPropertiesMixinIfaceInfo interface =
      { 0, properties, NULL, NULL };

  dbus_g_object_type_install_info (mc_svc_account_interface_hidden_get_type (),
      &_mc_svc_account_interface_hidden_object_info);

  interface.dbus_interface = g_quark_from_static_string ("org.freedesktop.Telepathy.Account.Interface.Hidden.DRAFT1");
  properties[0].name = g_quark_from_static_string ("Hidden");
  properties[0].type = G_TYPE_BOOLEAN;
  tp_svc_interface_set_dbus_properties_info (MC_TYPE_SVC_ACCOUNT_INTERFACE_HIDDEN, &interface);

}
static void
mc_svc_account_interface_hidden_base_init (gpointer klass)
{
  static gboolean initialized = FALSE;

  if (!initialized)
    {
      initialized = TRUE;
      mc_svc_account_interface_hidden_base_init_once (klass);
    }
}
static const DBusGMethodInfo _mc_svc_account_interface_hidden_methods[] = {
  { NULL, NULL, 0 }
};

static const DBusGObjectInfo _mc_svc_account_interface_hidden_object_info = {
  0,
  _mc_svc_account_interface_hidden_methods,
  0,
"\0",
"\0\0",
"\0\0",
};


