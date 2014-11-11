#include "_gen/svc-Account_Interface_External_Password_Storage.h"

#include <telepathy-glib/telepathy-glib.h>
#include "_gen/signals-marshal.h"

static const DBusGObjectInfo _mc_svc_account_interface_external_password_storage_object_info;

struct _McSvcAccountInterfaceExternalPasswordStorageClass {
    GTypeInterface parent_class;
    mc_svc_account_interface_external_password_storage_forget_password_impl forget_password;
};

static void mc_svc_account_interface_external_password_storage_base_init (gpointer klass);

GType
mc_svc_account_interface_external_password_storage_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
        sizeof (McSvcAccountInterfaceExternalPasswordStorageClass),
        mc_svc_account_interface_external_password_storage_base_init, /* base_init */
        NULL, /* base_finalize */
        NULL, /* class_init */
        NULL, /* class_finalize */
        NULL, /* class_data */
        0,
        0, /* n_preallocs */
        NULL /* instance_init */
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
          "McSvcAccountInterfaceExternalPasswordStorage", &info, 0);
    }

  return type;
}

/**
 * mc_svc_account_interface_external_password_storage_forget_password_impl:
 * @self: The object implementing this interface
 * @context: Used to return values or throw an error
 *
 * The signature of an implementation of the D-Bus method
 * ForgetPassword on interface org.freedesktop.Telepathy.Account.Interface.ExternalPasswordStorage.DRAFT.
 */
static void
mc_svc_account_interface_external_password_storage_forget_password (McSvcAccountInterfaceExternalPasswordStorage *self,
    DBusGMethodInvocation *context)
{
  mc_svc_account_interface_external_password_storage_forget_password_impl impl = (MC_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE_GET_CLASS (self)->forget_password);

  if (impl != NULL)
    {
      (impl) (self,
        context);
    }
  else
    {
      tp_dbus_g_method_return_not_implemented (context);
    }
}

/**
 * mc_svc_account_interface_external_password_storage_implement_forget_password:
 * @klass: A class whose instances implement this interface
 * @impl: A callback used to implement the ForgetPassword D-Bus method
 *
 * Register an implementation for the ForgetPassword method in the vtable
 * of an implementation of this interface. To be called from
 * the interface init function.
 */
void
mc_svc_account_interface_external_password_storage_implement_forget_password (McSvcAccountInterfaceExternalPasswordStorageClass *klass, mc_svc_account_interface_external_password_storage_forget_password_impl impl)
{
  klass->forget_password = impl;
}

static inline void
mc_svc_account_interface_external_password_storage_base_init_once (gpointer klass G_GNUC_UNUSED)
{
  static TpDBusPropertiesMixinPropInfo properties[2] = {
      { 0, TP_DBUS_PROPERTIES_MIXIN_FLAG_READ, "b", 0, NULL, NULL }, /* PasswordSaved */
      { 0, 0, NULL, 0, NULL, NULL }
  };
  static TpDBusPropertiesMixinIfaceInfo interface =
      { 0, properties, NULL, NULL };

  dbus_g_object_type_install_info (mc_svc_account_interface_external_password_storage_get_type (),
      &_mc_svc_account_interface_external_password_storage_object_info);

  interface.dbus_interface = g_quark_from_static_string ("org.freedesktop.Telepathy.Account.Interface.ExternalPasswordStorage.DRAFT");
  properties[0].name = g_quark_from_static_string ("PasswordSaved");
  properties[0].type = G_TYPE_BOOLEAN;
  tp_svc_interface_set_dbus_properties_info (MC_TYPE_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE, &interface);

}
static void
mc_svc_account_interface_external_password_storage_base_init (gpointer klass)
{
  static gboolean initialized = FALSE;

  if (!initialized)
    {
      initialized = TRUE;
      mc_svc_account_interface_external_password_storage_base_init_once (klass);
    }
}
static const DBusGMethodInfo _mc_svc_account_interface_external_password_storage_methods[] = {
  { (GCallback) mc_svc_account_interface_external_password_storage_forget_password, g_cclosure_marshal_VOID__POINTER, 0 },
};

static const DBusGObjectInfo _mc_svc_account_interface_external_password_storage_object_info = {
  0,
  _mc_svc_account_interface_external_password_storage_methods,
  1,
"org.freedesktop.Telepathy.Account.Interface.ExternalPasswordStorage.DRAFT\0ForgetPassword\0A\0\0\0",
"\0\0",
"\0\0",
};


