#include <glib-object.h>
#include <dbus/dbus-glib.h>
#include <telepathy-glib/dbus-properties-mixin.h>

G_BEGIN_DECLS

/**
 * McSvcAccountInterfaceExternalPasswordStorage:
 *
 * Dummy typedef representing any implementation of this interface.
 */
typedef struct _McSvcAccountInterfaceExternalPasswordStorage McSvcAccountInterfaceExternalPasswordStorage;

/**
 * McSvcAccountInterfaceExternalPasswordStorageClass:
 *
 * The class of McSvcAccountInterfaceExternalPasswordStorage.
 */
typedef struct _McSvcAccountInterfaceExternalPasswordStorageClass McSvcAccountInterfaceExternalPasswordStorageClass;

GType mc_svc_account_interface_external_password_storage_get_type (void);
#define MC_TYPE_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE \
  (mc_svc_account_interface_external_password_storage_get_type ())
#define MC_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE, McSvcAccountInterfaceExternalPasswordStorage))
#define MC_IS_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE))
#define MC_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_EXTERNAL_PASSWORD_STORAGE, McSvcAccountInterfaceExternalPasswordStorageClass))


typedef void (*mc_svc_account_interface_external_password_storage_forget_password_impl) (McSvcAccountInterfaceExternalPasswordStorage *self,
    DBusGMethodInvocation *context);
void mc_svc_account_interface_external_password_storage_implement_forget_password (McSvcAccountInterfaceExternalPasswordStorageClass *klass, mc_svc_account_interface_external_password_storage_forget_password_impl impl);
/**
 * mc_svc_account_interface_external_password_storage_return_from_forget_password:
 * @context: The D-Bus method invocation context
 *
 * Return successfully by calling dbus_g_method_return().
 * This inline function exists only to provide type-safety.
 */
static inline
/* this comment is to stop gtkdoc realising this is static */
void mc_svc_account_interface_external_password_storage_return_from_forget_password (DBusGMethodInvocation *context);
static inline void
mc_svc_account_interface_external_password_storage_return_from_forget_password (DBusGMethodInvocation *context)
{
  dbus_g_method_return (context);
}



G_END_DECLS
