#include <glib-object.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

typedef struct _IdleSvcConnectionInterfaceRenaming IdleSvcConnectionInterfaceRenaming;

typedef struct _IdleSvcConnectionInterfaceRenamingClass IdleSvcConnectionInterfaceRenamingClass;

GType idle_svc_connection_interface_renaming_get_type (void);
#define IDLE_TYPE_SVC_CONNECTION_INTERFACE_RENAMING \
  (idle_svc_connection_interface_renaming_get_type ())
#define IDLE_SVC_CONNECTION_INTERFACE_RENAMING(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), IDLE_TYPE_SVC_CONNECTION_INTERFACE_RENAMING, IdleSvcConnectionInterfaceRenaming))
#define IDLE_IS_SVC_CONNECTION_INTERFACE_RENAMING(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), IDLE_TYPE_SVC_CONNECTION_INTERFACE_RENAMING))
#define IDLE_SVC_CONNECTION_INTERFACE_RENAMING_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), IDLE_TYPE_SVC_CONNECTION_INTERFACE_RENAMING, IdleSvcConnectionInterfaceRenamingClass))


typedef void (*idle_svc_connection_interface_renaming_request_rename_impl) (IdleSvcConnectionInterfaceRenaming *self,
    const gchar *in_Identifier,
    DBusGMethodInvocation *context);
void idle_svc_connection_interface_renaming_implement_request_rename (IdleSvcConnectionInterfaceRenamingClass *klass, idle_svc_connection_interface_renaming_request_rename_impl impl);
static inline
/* this comment is to stop gtkdoc realising this is static */
void idle_svc_connection_interface_renaming_return_from_request_rename (DBusGMethodInvocation *context);
static inline void
idle_svc_connection_interface_renaming_return_from_request_rename (DBusGMethodInvocation *context)
{
  dbus_g_method_return (context);
}

void idle_svc_connection_interface_renaming_emit_renamed (gpointer instance,
    guint arg_Original,
    guint arg_New);


G_END_DECLS
