/* We don't want gtkdoc scanning this file, it'll get
 * confused by seeing function definitions, so mark it as: */
/*<private_header>*/

/**
 * mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials:
 * @proxy: the proxy on which the call was made
 * @error: %NULL on success, or an error on failure
 * @user_data: user-supplied data
 * @weak_object: user-supplied object
 *
 * Signature of the callback called when a ForgetCredentials method call
 * succeeds or fails.
 */
static void
_mc_cli_connection_manager_interface_account_storage_collect_callback_forget_credentials (DBusGProxy *proxy,
    DBusGProxyCall *call,
    gpointer user_data)
{
  GError *error = NULL;

  dbus_g_proxy_end_call (proxy, call, &error,
      G_TYPE_INVALID);
  tp_proxy_pending_call_v0_take_results (user_data, error,NULL);
}
static void
_mc_cli_connection_manager_interface_account_storage_invoke_callback_forget_credentials (TpProxy *self,
    GError *error,
    GValueArray *args,
    GCallback generic_callback,
    gpointer user_data,
    GObject *weak_object)
{
  mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials callback = (mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials) generic_callback;

  if (error != NULL)
    {
      callback ((TpProxy *) self,
          error, user_data, weak_object);
      g_error_free (error);
      return;
    }
  callback ((TpProxy *) self,
      error, user_data, weak_object);

  if (args != NULL)
    g_value_array_free (args);
}

/**
 * mc_cli_connection_manager_interface_account_storage_call_forget_credentials:
 * @proxy: the #TpProxy
 * @timeout_ms: the timeout in milliseconds, or -1 to use the
 *   default
 * @in_Account_Id: Used to pass an 'in' argument: An account id as returned from &lt;tp:dbus-ref namespace=&quot;org.freedesktop.Telepathy&quot;&gt;Protocol.IdentifyAccount&lt;/tp:dbus-ref&gt;.
 * @callback: called when the method call succeeds or fails;
 *   may be %NULL to make a "fire and forget" call with no 
 *   reply tracking
 * @user_data: user-supplied data passed to the callback;
 *   must be %NULL if @callback is %NULL
 * @destroy: called with the user_data as argument, after the
 *   call has succeeded, failed or been cancelled;
 *   must be %NULL if @callback is %NULL
 * @weak_object: If not %NULL, a #GObject which will be 
 *   weakly referenced; if it is destroyed, this call 
 *   will automatically be cancelled. Must be %NULL if 
 *   @callback is %NULL
 *
 * Start a ForgetCredentials method call.
 *
 * Clears any saved credentials associated with the specified Account_Id.         Any other saved data related to the account will be unaffected.
 *
 * Returns: a #TpProxyPendingCall representing the call in
 *  progress. It is borrowed from the object, and will become
 *  invalid when the callback is called, the call is
 *  cancelled or the #TpProxy becomes invalid.
 */
TpProxyPendingCall *
mc_cli_connection_manager_interface_account_storage_call_forget_credentials (gpointer proxy,
    gint timeout_ms,
    const gchar *in_Account_Id,
    mc_cli_connection_manager_interface_account_storage_callback_for_forget_credentials callback,
    gpointer user_data,
    GDestroyNotify destroy,
    GObject *weak_object)
{
  GError *error = NULL;
  GQuark interface = MC_IFACE_QUARK_CONNECTION_MANAGER_INTERFACE_ACCOUNT_STORAGE;
  DBusGProxy *iface;

  g_return_val_if_fail (TP_IS_PROXY (proxy), NULL);
  g_return_val_if_fail (callback != NULL || user_data == NULL, NULL);
  g_return_val_if_fail (callback != NULL || destroy == NULL, NULL);
  g_return_val_if_fail (callback != NULL || weak_object == NULL, NULL);

  iface = tp_proxy_borrow_interface_by_id (
      (TpProxy *) proxy,
      interface, &error);

  if (iface == NULL)
    {
      if (callback != NULL)
        callback (proxy,
            error, user_data, weak_object);

      if (destroy != NULL)
        destroy (user_data);

      g_error_free (error);
      return NULL;
    }

  if (callback == NULL)
    {
      dbus_g_proxy_call_no_reply (iface, "ForgetCredentials",
          G_TYPE_STRING, in_Account_Id,
          G_TYPE_INVALID);
      return NULL;
    }
  else
    {
      TpProxyPendingCall *data;

      data = tp_proxy_pending_call_v0_new ((TpProxy *) proxy,
          interface, "ForgetCredentials", iface,
          _mc_cli_connection_manager_interface_account_storage_invoke_callback_forget_credentials,
          G_CALLBACK (callback), user_data, destroy,
          weak_object, FALSE);
      tp_proxy_pending_call_v0_take_pending_call (data,
          dbus_g_proxy_begin_call_with_timeout (iface,
              "ForgetCredentials",
              _mc_cli_connection_manager_interface_account_storage_collect_callback_forget_credentials,
              data,
              tp_proxy_pending_call_v0_completed,
              timeout_ms,
              G_TYPE_STRING, in_Account_Id,
              G_TYPE_INVALID));

      return data;
    }
}


/**
 * mc_cli_connection_manager_interface_account_storage_callback_for_remove_account:
 * @proxy: the proxy on which the call was made
 * @error: %NULL on success, or an error on failure
 * @user_data: user-supplied data
 * @weak_object: user-supplied object
 *
 * Signature of the callback called when a RemoveAccount method call
 * succeeds or fails.
 */
static void
_mc_cli_connection_manager_interface_account_storage_collect_callback_remove_account (DBusGProxy *proxy,
    DBusGProxyCall *call,
    gpointer user_data)
{
  GError *error = NULL;

  dbus_g_proxy_end_call (proxy, call, &error,
      G_TYPE_INVALID);
  tp_proxy_pending_call_v0_take_results (user_data, error,NULL);
}
static void
_mc_cli_connection_manager_interface_account_storage_invoke_callback_remove_account (TpProxy *self,
    GError *error,
    GValueArray *args,
    GCallback generic_callback,
    gpointer user_data,
    GObject *weak_object)
{
  mc_cli_connection_manager_interface_account_storage_callback_for_remove_account callback = (mc_cli_connection_manager_interface_account_storage_callback_for_remove_account) generic_callback;

  if (error != NULL)
    {
      callback ((TpProxy *) self,
          error, user_data, weak_object);
      g_error_free (error);
      return;
    }
  callback ((TpProxy *) self,
      error, user_data, weak_object);

  if (args != NULL)
    g_value_array_free (args);
}

/**
 * mc_cli_connection_manager_interface_account_storage_call_remove_account:
 * @proxy: the #TpProxy
 * @timeout_ms: the timeout in milliseconds, or -1 to use the
 *   default
 * @in_Account_Id: Used to pass an 'in' argument: An account id as returned from &lt;tp:dbus-ref namespace=&quot;org.freedesktop.Telepathy&quot;&gt;Protocol.IdentifyAccount&lt;/tp:dbus-ref&gt;.
 * @callback: called when the method call succeeds or fails;
 *   may be %NULL to make a "fire and forget" call with no 
 *   reply tracking
 * @user_data: user-supplied data passed to the callback;
 *   must be %NULL if @callback is %NULL
 * @destroy: called with the user_data as argument, after the
 *   call has succeeded, failed or been cancelled;
 *   must be %NULL if @callback is %NULL
 * @weak_object: If not %NULL, a #GObject which will be 
 *   weakly referenced; if it is destroyed, this call 
 *   will automatically be cancelled. Must be %NULL if 
 *   @callback is %NULL
 *
 * Start a RemoveAccount method call.
 *
 * Completely removes all data associated with an account from the         connection manager&apos;s internal storage.
 *
 * Returns: a #TpProxyPendingCall representing the call in
 *  progress. It is borrowed from the object, and will become
 *  invalid when the callback is called, the call is
 *  cancelled or the #TpProxy becomes invalid.
 */
TpProxyPendingCall *
mc_cli_connection_manager_interface_account_storage_call_remove_account (gpointer proxy,
    gint timeout_ms,
    const gchar *in_Account_Id,
    mc_cli_connection_manager_interface_account_storage_callback_for_remove_account callback,
    gpointer user_data,
    GDestroyNotify destroy,
    GObject *weak_object)
{
  GError *error = NULL;
  GQuark interface = MC_IFACE_QUARK_CONNECTION_MANAGER_INTERFACE_ACCOUNT_STORAGE;
  DBusGProxy *iface;

  g_return_val_if_fail (TP_IS_PROXY (proxy), NULL);
  g_return_val_if_fail (callback != NULL || user_data == NULL, NULL);
  g_return_val_if_fail (callback != NULL || destroy == NULL, NULL);
  g_return_val_if_fail (callback != NULL || weak_object == NULL, NULL);

  iface = tp_proxy_borrow_interface_by_id (
      (TpProxy *) proxy,
      interface, &error);

  if (iface == NULL)
    {
      if (callback != NULL)
        callback (proxy,
            error, user_data, weak_object);

      if (destroy != NULL)
        destroy (user_data);

      g_error_free (error);
      return NULL;
    }

  if (callback == NULL)
    {
      dbus_g_proxy_call_no_reply (iface, "RemoveAccount",
          G_TYPE_STRING, in_Account_Id,
          G_TYPE_INVALID);
      return NULL;
    }
  else
    {
      TpProxyPendingCall *data;

      data = tp_proxy_pending_call_v0_new ((TpProxy *) proxy,
          interface, "RemoveAccount", iface,
          _mc_cli_connection_manager_interface_account_storage_invoke_callback_remove_account,
          G_CALLBACK (callback), user_data, destroy,
          weak_object, FALSE);
      tp_proxy_pending_call_v0_take_pending_call (data,
          dbus_g_proxy_begin_call_with_timeout (iface,
              "RemoveAccount",
              _mc_cli_connection_manager_interface_account_storage_collect_callback_remove_account,
              data,
              tp_proxy_pending_call_v0_completed,
              timeout_ms,
              G_TYPE_STRING, in_Account_Id,
              G_TYPE_INVALID));

      return data;
    }
}


/*
 * mc_cli_Connection_Manager_Interface_Account_Storage_add_signals:
 * @self: the #TpProxy
 * @quark: a quark whose string value is the interface
 *   name whose signals should be added
 * @proxy: the D-Bus proxy to which to add the signals
 * @unused: not used for anything
 *
 * Tell dbus-glib that @proxy has the signatures of all
 * signals on the given interface, if it's one we
 * support.
 *
 * This function should be used as a signal handler for
 * #TpProxy::interface-added.
 */
static void
mc_cli_Connection_Manager_Interface_Account_Storage_add_signals (TpProxy *self G_GNUC_UNUSED,
    guint quark,
    DBusGProxy *proxy,
    gpointer unused G_GNUC_UNUSED)
{
}
