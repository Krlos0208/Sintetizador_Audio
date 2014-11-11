#include "_gen/svc.h"

#include <telepathy-glib/dbus.h>

static const DBusGObjectInfo _idle_svc_connection_interface_renaming_object_info;

struct _IdleSvcConnectionInterfaceRenamingClass {
    GTypeInterface parent_class;
    idle_svc_connection_interface_renaming_request_rename_impl request_rename_cb;
};

enum {
    SIGNAL_CONNECTION_INTERFACE_RENAMING_Renamed,
    N_CONNECTION_INTERFACE_RENAMING_SIGNALS
};
static guint connection_interface_renaming_signals[N_CONNECTION_INTERFACE_RENAMING_SIGNALS] = {0};

static void idle_svc_connection_interface_renaming_base_init (gpointer klass);

GType
idle_svc_connection_interface_renaming_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (type == 0))
    {
      static const GTypeInfo info = {
        sizeof (IdleSvcConnectionInterfaceRenamingClass),
        idle_svc_connection_interface_renaming_base_init, /* base_init */
        NULL, /* base_finalize */
        NULL, /* class_init */
        NULL, /* class_finalize */
        NULL, /* class_data */
        0,
        0, /* n_preallocs */
        NULL /* instance_init */
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
          "IdleSvcConnectionInterfaceRenaming", &info, 0);
    }

  return type;
}

static void
idle_svc_connection_interface_renaming_request_rename (IdleSvcConnectionInterfaceRenaming *self,
    const gchar *in_Identifier,
    DBusGMethodInvocation *context)
{
  idle_svc_connection_interface_renaming_request_rename_impl impl = (IDLE_SVC_CONNECTION_INTERFACE_RENAMING_GET_CLASS (self)->request_rename_cb);

  if (impl != NULL)
    {
      (impl) (self,
        in_Identifier,
        context);
    }
  else
    {
      tp_dbus_g_method_return_not_implemented (context);
    }
}

void
idle_svc_connection_interface_renaming_implement_request_rename (IdleSvcConnectionInterfaceRenamingClass *klass, idle_svc_connection_interface_renaming_request_rename_impl impl)
{
  klass->request_rename_cb = impl;
}

void
idle_svc_connection_interface_renaming_emit_renamed (gpointer instance,
    guint arg_Original,
    guint arg_New)
{
  g_assert (instance != NULL);
  g_assert (G_TYPE_CHECK_INSTANCE_TYPE (instance, IDLE_TYPE_SVC_CONNECTION_INTERFACE_RENAMING));
  g_signal_emit (instance,
      connection_interface_renaming_signals[SIGNAL_CONNECTION_INTERFACE_RENAMING_Renamed],
      0,
      arg_Original,
      arg_New);
}

static inline void
idle_svc_connection_interface_renaming_base_init_once (gpointer klass G_GNUC_UNUSED)
{
  dbus_g_object_type_install_info (idle_svc_connection_interface_renaming_get_type (),
      &_idle_svc_connection_interface_renaming_object_info);

  connection_interface_renaming_signals[SIGNAL_CONNECTION_INTERFACE_RENAMING_Renamed] =
  g_signal_new ("renamed",
      G_OBJECT_CLASS_TYPE (klass),
      G_SIGNAL_RUN_LAST|G_SIGNAL_DETAILED,
      0,
      NULL, NULL,
      g_cclosure_marshal_generic,
      G_TYPE_NONE,
      2,
      G_TYPE_UINT,
      G_TYPE_UINT);

}
static void
idle_svc_connection_interface_renaming_base_init (gpointer klass)
{
  static gboolean initialized = FALSE;

  if (!initialized)
    {
      initialized = TRUE;
      idle_svc_connection_interface_renaming_base_init_once (klass);
    }
}
static const DBusGMethodInfo _idle_svc_connection_interface_renaming_methods[] = {
  { (GCallback) idle_svc_connection_interface_renaming_request_rename, g_cclosure_marshal_generic, 0 },
};

static const DBusGObjectInfo _idle_svc_connection_interface_renaming_object_info = {
  0,
  _idle_svc_connection_interface_renaming_methods,
  1,
"org.freedesktop.Telepathy.Connection.Interface.Renaming\0RequestRename\0A\0Identifier\0I\0s\0\0\0",
"org.freedesktop.Telepathy.Connection.Interface.Renaming\0Renamed\0\0",
"\0\0",
};


