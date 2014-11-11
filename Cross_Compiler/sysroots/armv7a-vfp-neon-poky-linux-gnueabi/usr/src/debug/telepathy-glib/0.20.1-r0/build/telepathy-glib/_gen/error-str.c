#include <telepathy-glib/errors.h>

const gchar *
tp_error_get_dbus_name (TpError error)
{
  switch (error)
    {
      case TP_ERROR_NETWORK_ERROR:
        return TP_ERROR_STR_NETWORK_ERROR;
      case TP_ERROR_NOT_IMPLEMENTED:
        return TP_ERROR_STR_NOT_IMPLEMENTED;
      case TP_ERROR_INVALID_ARGUMENT:
        return TP_ERROR_STR_INVALID_ARGUMENT;
      case TP_ERROR_NOT_AVAILABLE:
        return TP_ERROR_STR_NOT_AVAILABLE;
      case TP_ERROR_PERMISSION_DENIED:
        return TP_ERROR_STR_PERMISSION_DENIED;
      case TP_ERROR_DISCONNECTED:
        return TP_ERROR_STR_DISCONNECTED;
      case TP_ERROR_INVALID_HANDLE:
        return TP_ERROR_STR_INVALID_HANDLE;
      case TP_ERROR_CHANNEL_BANNED:
        return TP_ERROR_STR_CHANNEL_BANNED;
      case TP_ERROR_CHANNEL_FULL:
        return TP_ERROR_STR_CHANNEL_FULL;
      case TP_ERROR_CHANNEL_INVITE_ONLY:
        return TP_ERROR_STR_CHANNEL_INVITE_ONLY;
      case TP_ERROR_NOT_YOURS:
        return TP_ERROR_STR_NOT_YOURS;
      case TP_ERROR_CANCELLED:
        return TP_ERROR_STR_CANCELLED;
      case TP_ERROR_AUTHENTICATION_FAILED:
        return TP_ERROR_STR_AUTHENTICATION_FAILED;
      case TP_ERROR_ENCRYPTION_NOT_AVAILABLE:
        return TP_ERROR_STR_ENCRYPTION_NOT_AVAILABLE;
      case TP_ERROR_ENCRYPTION_ERROR:
        return TP_ERROR_STR_ENCRYPTION_ERROR;
      case TP_ERROR_CERT_NOT_PROVIDED:
        return TP_ERROR_STR_CERT_NOT_PROVIDED;
      case TP_ERROR_CERT_UNTRUSTED:
        return TP_ERROR_STR_CERT_UNTRUSTED;
      case TP_ERROR_CERT_EXPIRED:
        return TP_ERROR_STR_CERT_EXPIRED;
      case TP_ERROR_CERT_NOT_ACTIVATED:
        return TP_ERROR_STR_CERT_NOT_ACTIVATED;
      case TP_ERROR_CERT_FINGERPRINT_MISMATCH:
        return TP_ERROR_STR_CERT_FINGERPRINT_MISMATCH;
      case TP_ERROR_CERT_HOSTNAME_MISMATCH:
        return TP_ERROR_STR_CERT_HOSTNAME_MISMATCH;
      case TP_ERROR_CERT_SELF_SIGNED:
        return TP_ERROR_STR_CERT_SELF_SIGNED;
      case TP_ERROR_CERT_REVOKED:
        return TP_ERROR_STR_CERT_REVOKED;
      case TP_ERROR_CERT_INSECURE:
        return TP_ERROR_STR_CERT_INSECURE;
      case TP_ERROR_CERT_INVALID:
        return TP_ERROR_STR_CERT_INVALID;
      case TP_ERROR_CERT_LIMIT_EXCEEDED:
        return TP_ERROR_STR_CERT_LIMIT_EXCEEDED;
      case TP_ERROR_NOT_CAPABLE:
        return TP_ERROR_STR_NOT_CAPABLE;
      case TP_ERROR_OFFLINE:
        return TP_ERROR_STR_OFFLINE;
      case TP_ERROR_CHANNEL_KICKED:
        return TP_ERROR_STR_CHANNEL_KICKED;
      case TP_ERROR_BUSY:
        return TP_ERROR_STR_BUSY;
      case TP_ERROR_NO_ANSWER:
        return TP_ERROR_STR_NO_ANSWER;
      case TP_ERROR_DOES_NOT_EXIST:
        return TP_ERROR_STR_DOES_NOT_EXIST;
      case TP_ERROR_TERMINATED:
        return TP_ERROR_STR_TERMINATED;
      case TP_ERROR_MEDIA_CODECS_INCOMPATIBLE:
        return TP_ERROR_STR_MEDIA_CODECS_INCOMPATIBLE;
      case TP_ERROR_MEDIA_UNSUPPORTED_TYPE:
        return TP_ERROR_STR_MEDIA_UNSUPPORTED_TYPE;
      case TP_ERROR_MEDIA_STREAMING_ERROR:
        return TP_ERROR_STR_MEDIA_STREAMING_ERROR;
      case TP_ERROR_CONNECTION_REFUSED:
        return TP_ERROR_STR_CONNECTION_REFUSED;
      case TP_ERROR_CONNECTION_FAILED:
        return TP_ERROR_STR_CONNECTION_FAILED;
      case TP_ERROR_CONNECTION_LOST:
        return TP_ERROR_STR_CONNECTION_LOST;
      case TP_ERROR_ALREADY_CONNECTED:
        return TP_ERROR_STR_ALREADY_CONNECTED;
      case TP_ERROR_CONNECTION_REPLACED:
        return TP_ERROR_STR_CONNECTION_REPLACED;
      case TP_ERROR_REGISTRATION_EXISTS:
        return TP_ERROR_STR_REGISTRATION_EXISTS;
      case TP_ERROR_SERVICE_BUSY:
        return TP_ERROR_STR_SERVICE_BUSY;
      case TP_ERROR_RESOURCE_UNAVAILABLE:
        return TP_ERROR_STR_RESOURCE_UNAVAILABLE;
      case TP_ERROR_WOULD_BREAK_ANONYMITY:
        return TP_ERROR_STR_WOULD_BREAK_ANONYMITY;
      case TP_ERROR_NOT_YET:
        return TP_ERROR_STR_NOT_YET;
      case TP_ERROR_REJECTED:
        return TP_ERROR_STR_REJECTED;
      case TP_ERROR_PICKED_UP_ELSEWHERE:
        return TP_ERROR_STR_PICKED_UP_ELSEWHERE;
      case TP_ERROR_SERVICE_CONFUSED:
        return TP_ERROR_STR_SERVICE_CONFUSED;
      case TP_ERROR_CONFUSED:
        return TP_ERROR_STR_CONFUSED;
      case TP_ERROR_SOFTWARE_UPGRADE_REQUIRED:
        return TP_ERROR_STR_SOFTWARE_UPGRADE_REQUIRED;
      case TP_ERROR_EMERGENCY_CALLS_NOT_SUPPORTED:
        return TP_ERROR_STR_EMERGENCY_CALLS_NOT_SUPPORTED;
      case TP_ERROR_INSUFFICIENT_BALANCE:
        return TP_ERROR_STR_INSUFFICIENT_BALANCE;
      case TP_ERROR_CAPTCHA_NOT_SUPPORTED:
        return TP_ERROR_STR_CAPTCHA_NOT_SUPPORTED;
      default:
        g_return_val_if_reached (NULL);
    }
}
