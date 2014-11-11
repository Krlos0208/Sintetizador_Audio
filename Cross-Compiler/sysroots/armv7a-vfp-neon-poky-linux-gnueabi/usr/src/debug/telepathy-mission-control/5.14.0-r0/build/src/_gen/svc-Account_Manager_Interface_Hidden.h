#include <glib-object.h>
#include <dbus/dbus-glib.h>
#include <telepathy-glib/dbus-properties-mixin.h>

G_BEGIN_DECLS

/**
 * McSvcAccountManagerInterfaceHidden:
 *
 * Dummy typedef representing any implementation of this interface.
 */
typedef struct _McSvcAccountManagerInterfaceHidden McSvcAccountManagerInterfaceHidden;

/**
 * McSvcAccountManagerInterfaceHiddenClass:
 *
 * The class of McSvcAccountManagerInterfaceHidden.
 */
typedef struct _McSvcAccountManagerInterfaceHiddenClass McSvcAccountManagerInterfaceHiddenClass;

GType mc_svc_account_manager_interface_hidden_get_type (void);
#define MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN \
  (mc_svc_account_manager_interface_hidden_get_type ())
#define MC_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN, McSvcAccountManagerInterfaceHidden))
#define MC_IS_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN))
#define MC_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), MC_TYPE_SVC_ACCOUNT_MANAGER_INTERFACE_HIDDEN, McSvcAccountManagerInterfaceHiddenClass))


void mc_svc_account_manager_interface_hidden_emit_hidden_account_removed (gpointer instance,
    const gchar *arg_Account);
void mc_svc_account_manager_interface_hidden_emit_hidden_account_validity_changed (gpointer instance,
    const gchar *arg_Account,
    gboolean arg_Valid);


G_END_DECLS
