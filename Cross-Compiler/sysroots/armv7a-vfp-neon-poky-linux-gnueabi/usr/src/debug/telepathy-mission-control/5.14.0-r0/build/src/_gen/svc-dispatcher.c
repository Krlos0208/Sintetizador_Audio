#include "_gen/svc-dispatcher.h"

#include <telepathy-glib/telepathy-glib.h>
#include "_gen/signals-marshal.h"

static const DBusGObjectInfo _mc_svc_channel_dispatcher_interface_messages_draft_object_info;

struct _McSvcChannelDispatcherInterfaceMessagesDraftClass {
    GTypeInterface parent_class;
    mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl send_message;
};

static void mc_svc_channel_dispatcher_interface_messages_draft_base_init (gpointer klass);

GType
mc_svc_channel_dispatcher_interface_messages_draft_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
        sizeof (McSvcChannelDispatcherInterfaceMessagesDraftClass),
        mc_svc_channel_dispatcher_interface_messages_draft_base_init, /* base_init */
        NULL, /* base_finalize */
        NULL, /* class_init */
        NULL, /* class_finalize */
        NULL, /* class_data */
        0,
        0, /* n_preallocs */
        NULL /* instance_init */
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
          "McSvcChannelDispatcherInterfaceMessagesDraft", &info, 0);
    }

  return type;
}

/**
 * mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl:
 * @self: The object implementing this interface
 * @in_Account: const gchar * (FIXME, generate documentation)
 * @in_TargetID: const gchar * (FIXME, generate documentation)
 * @in_Message: const GPtrArray * (FIXME, generate documentation)
 * @in_Flags: guint  (FIXME, generate documentation)
 * @context: Used to return values or throw an error
 *
 * The signature of an implementation of the D-Bus method
 * SendMessage on interface org.freedesktop.Telepathy.ChannelDispatcher.Interface.Messages.DRAFT.
 */
static void
mc_svc_channel_dispatcher_interface_messages_draft_send_message (McSvcChannelDispatcherInterfaceMessagesDraft *self,
    const gchar *in_Account,
    const gchar *in_TargetID,
    const GPtrArray *in_Message,
    guint in_Flags,
    DBusGMethodInvocation *context)
{
  mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl impl = (MC_SVC_CHANNEL_DISPATCHER_INTERFACE_MESSAGES_DRAFT_GET_CLASS (self)->send_message);

  if (impl != NULL)
    {
      (impl) (self,
        in_Account,
        in_TargetID,
        in_Message,
        in_Flags,
        context);
    }
  else
    {
      tp_dbus_g_method_return_not_implemented (context);
    }
}

/**
 * mc_svc_channel_dispatcher_interface_messages_draft_implement_send_message:
 * @klass: A class whose instances implement this interface
 * @impl: A callback used to implement the SendMessage D-Bus method
 *
 * Register an implementation for the SendMessage method in the vtable
 * of an implementation of this interface. To be called from
 * the interface init function.
 */
void
mc_svc_channel_dispatcher_interface_messages_draft_implement_send_message (McSvcChannelDispatcherInterfaceMessagesDraftClass *klass, mc_svc_channel_dispatcher_interface_messages_draft_send_message_impl impl)
{
  klass->send_message = impl;
}

static inline void
mc_svc_channel_dispatcher_interface_messages_draft_base_init_once (gpointer klass G_GNUC_UNUSED)
{
  dbus_g_object_type_install_info (mc_svc_channel_dispatcher_interface_messages_draft_get_type (),
      &_mc_svc_channel_dispatcher_interface_messages_draft_object_info);

}
static void
mc_svc_channel_dispatcher_interface_messages_draft_base_init (gpointer klass)
{
  static gboolean initialized = FALSE;

  if (!initialized)
    {
      initialized = TRUE;
      mc_svc_channel_dispatcher_interface_messages_draft_base_init_once (klass);
    }
}
static const DBusGMethodInfo _mc_svc_channel_dispatcher_interface_messages_draft_methods[] = {
  { (GCallback) mc_svc_channel_dispatcher_interface_messages_draft_send_message, _mcd_ext_marshal_VOID__BOXED_STRING_BOXED_UINT_POINTER, 0 },
};

static const DBusGObjectInfo _mc_svc_channel_dispatcher_interface_messages_draft_object_info = {
  0,
  _mc_svc_channel_dispatcher_interface_messages_draft_methods,
  1,
"org.freedesktop.Telepathy.ChannelDispatcher.Interface.Messages.DRAFT\0SendMessage\0A\0Account\0I\0o\0TargetID\0I\0s\0Message\0I\0aa{sv}\0Flags\0I\0u\0Token\0O\0F\0N\0s\0\0\0",
"\0\0",
"\0\0",
};


