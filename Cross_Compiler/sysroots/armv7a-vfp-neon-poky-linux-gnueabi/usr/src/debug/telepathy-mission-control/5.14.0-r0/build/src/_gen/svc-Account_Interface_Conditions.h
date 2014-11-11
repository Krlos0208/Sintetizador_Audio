#include <glib-object.h>
#include <dbus/dbus-glib.h>
#include <telepathy-glib/dbus-properties-mixin.h>

G_BEGIN_DECLS

/**
 * McSvcAccountInterfaceConditions:
 *
 * Dummy typedef representing any implementation of this interface.
 */
typedef struct _McSvcAccountInterfaceConditions McSvcAccountInterfaceConditions;

/**
 * McSvcAccountInterfaceConditionsClass:
 *
 * The class of McSvcAccountInterfaceConditions.
 */
typedef struct _McSvcAccountInterfaceConditionsClass McSvcAccountInterfaceConditionsClass;

GType mc_svc_account_interface_conditions_get_type (void);
#define MC_TYPE_SVC_ACCOUNT_INTERFACE_CONDITIONS \
  (mc_svc_account_interface_conditions_get_type ())
#define MC_SVC_ACCOUNT_INTERFACE_CONDITIONS(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_CONDITIONS, McSvcAccountInterfaceConditions))
#define MC_IS_SVC_ACCOUNT_INTERFACE_CONDITIONS(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_CONDITIONS))
#define MC_SVC_ACCOUNT_INTERFACE_CONDITIONS_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), MC_TYPE_SVC_ACCOUNT_INTERFACE_CONDITIONS, McSvcAccountInterfaceConditionsClass))




G_END_DECLS
