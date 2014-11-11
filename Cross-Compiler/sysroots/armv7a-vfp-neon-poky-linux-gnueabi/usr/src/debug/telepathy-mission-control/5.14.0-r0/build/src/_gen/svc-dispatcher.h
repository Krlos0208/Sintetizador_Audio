#include <glib-object.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

/**
 * McSvcChannelDispatcherInterfaceMessagesDraft:
 *
 * Dummy typedef representing any implementation of this interface.
 */
typedef struct _McSvcChannelDispatcherInterfaceMessagesDraft McSvcChannelDispatcherInterfaceMessagesDraft;

/**
 * McSvcChannelDispatcherInterfaceMessagesDraftClass:
 *
 * The class of McSvcChannelDispatcherInterfaceMessagesDraft.
 */
typedef struct _McSvcChannelDispatcherInterfaceMessagesDraftClass McSvcChannelDispatcherInterfaceMessagesDraftClass;

GType mc_svc_channel_dispatcher_interface_messages_draft_get_type (void);
#define MC_TYPE_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT \
  (mc_svc_channel_dispatcher_interface_messages_draft_get_type ())
#define MC_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), MC_TYPE_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT, McSvcChannelDispatcherInterfaceMessagesDraft))
#define MC_IS_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), MC_TYPE_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT))
#define MC_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_INTERFACE((obj), MC_TYPE_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT, McSvcChannelDispatcherInterfaceMessagesDraftClass))


typedef void (*mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl) (McSvcChannelDispatcherInterfaceMessagesDraft *self,
    const gchar *in_Account,
    const gchar *in_TargetID,
    const GPtrArray *in_Message,
    guint in_Flags,
    DBusGMethodInvocation *context);
void mc_svc_channel_dispatcher_interface_messages_draft_implement_send_message (McSvcChannelDispatcherInterfaceMessagesDraftClass *klass, mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl impl);
/**
 * mc_svc_channel_dispatcher_interface_messages_draft_return_from_send_message:
 * @context: The D-Bus method invocation context
 * @out_Token: const gchar * (FIXME, generate documentation)
 *
 * Return successfully by calling dbus_g_method_return().
 * This inline function exists only to provide type-safety.
 */
static inline
/* this comment is to stop gtkdoc realising this is static */
void mc_svc_channel_dispatcher_interface_messages_draft_return_from_send_message (DBusGMethodInvocation *context,
    const gchar *out_Token);
static inline void
mc_svc_channel_dispatcher_interface_messages_draft_return_from_send_message (DBusGMethodInvocation *context,
    const gchar *out_Token)
{
  dbus_g_method_return (context,
      out_Token);
}



G_END_DECLS
