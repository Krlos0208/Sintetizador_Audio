#include <glib-object.h>
#include <dbus/dbus-glib.h>
#include <telepathy-glib/dbus-properties-mixin.h>

G_BEGIN_DECLS

/**
 * McSvcAccountInterfaceHidden:
 *
 * Dummy typedef representing any implementation of this interface.
 */
typedef struct _McSvcAccountInterfaceHidden McSvcAccountInterfaceHidden;

/**
 * McSvcAccountInterfaceHiddenClass:
 *
 * The class of McSvcAccountInterfaceHidden.
 */
typedef struct _McSvcAccountInterfaceHiddenClass McSvcAccountInterfaceHiddenClass;

GType mc_svc_account_interface_hidden_get_type (void);
#define MC_TYPE_SVC_ACCOUNT_INTERFACE_HIDDEN \
  (mc_svc_account_interface_hidden_get_type ())
#define MC_SVC_ACCOUNT_INTERFACE_HIDDEN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_HIDDEN, McSvcAccountInterfaceHidden))
#define MC_IS_SVC_ACCOUNT_INTERFACE_HIDDEN(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_HIDDEN))
#define MC_SVC_ACCOUNT_INTERFACE_HIDDEN_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_HIDDEN, McSvcAccountInterfaceHiddenClass))




G_END_DECLS
