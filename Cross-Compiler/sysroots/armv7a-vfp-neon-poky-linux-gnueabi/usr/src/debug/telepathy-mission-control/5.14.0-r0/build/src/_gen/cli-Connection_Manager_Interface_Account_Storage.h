G_BEGIN_DECLS

typedef void (*mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials) (TpProxy *proxy,
    const GError *error, gpointer user_data,
    GObject *weak_object);

TpProxyPendingCall *mc_cli_connection_manager_interface_account_storage_call_forget_credentials (gpointer proxy,
    gint timeout_ms,
    const gchar *in_Account_Id,
    mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials callback,
    gpointer user_data,
    GDestroyNotify destroy,
    GObject *weak_object);


typedef void (*mc_cli_connection_manager_interface_account_storage_callback_for_remove_account) (TpProxy *proxy,
    const GError *error, gpointer user_data,
    GObject *weak_object);

TpProxyPendingCall *mc_cli_connection_manager_interface_account_storage_call_remove_account (gpointer proxy,
    gint timeout_ms,
    const gchar *in_Account_Id,
    mc_cli_connection_manager_interface_account_storage_callback_for_remove_account callback,
    gpointer user_data,
    GDestroyNotify destroy,
    GObject *weak_object);


G_END_DECLS
