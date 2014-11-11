


#include "mcd-enum-types.h"
#define g_intern_static_string(s) (s)

/* enumerations from "mcd-account.h" */
GType
mcd_account_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MCD_ACCOUNT_ERROR_SET_PARAMETER, "MCD_ACCOUNT_ERROR_SET_PARAMETER", "set-parameter" },
      { MCD_ACCOUNT_ERROR_GET_PARAMETER, "MCD_ACCOUNT_ERROR_GET_PARAMETER", "get-parameter" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static (g_intern_static_string ("McdAccountError"), values);
  }
  return etype;
}

/* enumerations from "mcd-channel.h" */
GType
mcd_channel_status_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MCD_CHANNEL_STATUS_UNDISPATCHED, "MCD_CHANNEL_STATUS_UNDISPATCHED", "undispatched" },
      { MCD_CHANNEL_STATUS_REQUEST, "MCD_CHANNEL_STATUS_REQUEST", "request" },
      { MCD_CHANNEL_STATUS_REQUESTED, "MCD_CHANNEL_STATUS_REQUESTED", "requested" },
      { MCD_CHANNEL_STATUS_DISPATCHING, "MCD_CHANNEL_STATUS_DISPATCHING", "dispatching" },
      { MCD_CHANNEL_STATUS_HANDLER_INVOKED, "MCD_CHANNEL_STATUS_HANDLER_INVOKED", "handler-invoked" },
      { MCD_CHANNEL_STATUS_DISPATCHED, "MCD_CHANNEL_STATUS_DISPATCHED", "dispatched" },
      { MCD_CHANNEL_STATUS_FAILED, "MCD_CHANNEL_STATUS_FAILED", "failed" },
      { MCD_CHANNEL_STATUS_ABORTED, "MCD_CHANNEL_STATUS_ABORTED", "aborted" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static (g_intern_static_string ("McdChannelStatus"), values);
  }
  return etype;
}

/* enumerations from "mcd-transport.h" */
GType
mcd_transport_status_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MCD_TRANSPORT_STATUS_CONNECTED, "MCD_TRANSPORT_STATUS_CONNECTED", "connected" },
      { MCD_TRANSPORT_STATUS_CONNECTING, "MCD_TRANSPORT_STATUS_CONNECTING", "connecting" },
      { MCD_TRANSPORT_STATUS_DISCONNECTED, "MCD_TRANSPORT_STATUS_DISCONNECTED", "disconnected" },
      { MCD_TRANSPORT_STATUS_DISCONNECTING, "MCD_TRANSPORT_STATUS_DISCONNECTING", "disconnecting" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static (g_intern_static_string ("McdTransportStatus"), values);
  }
  return etype;
}

#define __MCD_ENUM_TYPES_C__



