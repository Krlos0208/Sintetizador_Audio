
/* Generated data (by glib-mkenums) */

#include "_gen/genums.h"

/* enumerations from "base-room-config.h" */
#include "base-room-config.h"

GType
tp_base_room_config_property_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { TP_BASE_ROOM_CONFIG_ANONYMOUS, "TP_BASE_ROOM_CONFIG_ANONYMOUS", "Anonymous" },
            { TP_BASE_ROOM_CONFIG_INVITE_ONLY, "TP_BASE_ROOM_CONFIG_INVITE_ONLY", "InviteOnly" },
            { TP_BASE_ROOM_CONFIG_LIMIT, "TP_BASE_ROOM_CONFIG_LIMIT", "Limit" },
            { TP_BASE_ROOM_CONFIG_MODERATED, "TP_BASE_ROOM_CONFIG_MODERATED", "Moderated" },
            { TP_BASE_ROOM_CONFIG_TITLE, "TP_BASE_ROOM_CONFIG_TITLE", "Title" },
            { TP_BASE_ROOM_CONFIG_DESCRIPTION, "TP_BASE_ROOM_CONFIG_DESCRIPTION", "Description" },
            { TP_BASE_ROOM_CONFIG_PERSISTENT, "TP_BASE_ROOM_CONFIG_PERSISTENT", "Persistent" },
            { TP_BASE_ROOM_CONFIG_PRIVATE, "TP_BASE_ROOM_CONFIG_PRIVATE", "Private" },
            { TP_BASE_ROOM_CONFIG_PASSWORD_PROTECTED, "TP_BASE_ROOM_CONFIG_PASSWORD_PROTECTED", "PasswordProtected" },
            { TP_BASE_ROOM_CONFIG_PASSWORD, "TP_BASE_ROOM_CONFIG_PASSWORD", "Password" },
            { TP_BASE_ROOM_CONFIG_PASSWORD_HINT, "TP_BASE_ROOM_CONFIG_PASSWORD_HINT", "PasswordHint" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("TpBaseRoomConfigProperty"), values);
    }
    return etype;
}

/* enumerations from "connection-manager.h" */
#include "connection-manager.h"

GType
tp_cm_info_source_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { TP_CM_INFO_SOURCE_NONE, "TP_CM_INFO_SOURCE_NONE", "none" },
            { TP_CM_INFO_SOURCE_FILE, "TP_CM_INFO_SOURCE_FILE", "file" },
            { TP_CM_INFO_SOURCE_LIVE, "TP_CM_INFO_SOURCE_LIVE", "live" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("TpCMInfoSource"), values);
    }
    return etype;
}

/* enumerations from "contact.h" */
#include "contact.h"

GType
tp_contact_feature_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { TP_CONTACT_FEATURE_ALIAS, "TP_CONTACT_FEATURE_ALIAS", "alias" },
            { TP_CONTACT_FEATURE_AVATAR_TOKEN, "TP_CONTACT_FEATURE_AVATAR_TOKEN", "avatar-token" },
            { TP_CONTACT_FEATURE_PRESENCE, "TP_CONTACT_FEATURE_PRESENCE", "presence" },
            { TP_CONTACT_FEATURE_LOCATION, "TP_CONTACT_FEATURE_LOCATION", "location" },
            { TP_CONTACT_FEATURE_CAPABILITIES, "TP_CONTACT_FEATURE_CAPABILITIES", "capabilities" },
            { TP_CONTACT_FEATURE_AVATAR_DATA, "TP_CONTACT_FEATURE_AVATAR_DATA", "avatar-data" },
            { TP_CONTACT_FEATURE_CONTACT_INFO, "TP_CONTACT_FEATURE_CONTACT_INFO", "contact-info" },
            { TP_CONTACT_FEATURE_CLIENT_TYPES, "TP_CONTACT_FEATURE_CLIENT_TYPES", "client-types" },
            { TP_CONTACT_FEATURE_SUBSCRIPTION_STATES, "TP_CONTACT_FEATURE_SUBSCRIPTION_STATES", "subscription-states" },
            { TP_CONTACT_FEATURE_CONTACT_GROUPS, "TP_CONTACT_FEATURE_CONTACT_GROUPS", "contact-groups" },
            { TP_CONTACT_FEATURE_CONTACT_BLOCKING, "TP_CONTACT_FEATURE_CONTACT_BLOCKING", "contact-blocking" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("TpContactFeature"), values);
    }
    return etype;
}

/* enumerations from "dbus.h" */
#include "dbus.h"

GType
tp_dbus_name_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { TP_DBUS_NAME_TYPE_UNIQUE, "TP_DBUS_NAME_TYPE_UNIQUE", "unique" },
            { TP_DBUS_NAME_TYPE_WELL_KNOWN, "TP_DBUS_NAME_TYPE_WELL_KNOWN", "well-known" },
            { TP_DBUS_NAME_TYPE_BUS_DAEMON, "TP_DBUS_NAME_TYPE_BUS_DAEMON", "bus-daemon" },
            { TP_DBUS_NAME_TYPE_NOT_BUS_DAEMON, "TP_DBUS_NAME_TYPE_NOT_BUS_DAEMON", "not-bus-daemon" },
            { TP_DBUS_NAME_TYPE_ANY, "TP_DBUS_NAME_TYPE_ANY", "any" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("TpDBusNameType"), values);
    }
    return etype;
}

/* enumerations from "dbus-properties-mixin.h" */
#include "dbus-properties-mixin.h"

GType
tp_dbus_properties_mixin_flags_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { TP_DBUS_PROPERTIES_MIXIN_FLAG_READ, "TP_DBUS_PROPERTIES_MIXIN_FLAG_READ", "read" },
            { TP_DBUS_PROPERTIES_MIXIN_FLAG_WRITE, "TP_DBUS_PROPERTIES_MIXIN_FLAG_WRITE", "write" },
            { TP_DBUS_PROPERTIES_MIXIN_FLAG_EMITS_CHANGED, "TP_DBUS_PROPERTIES_MIXIN_FLAG_EMITS_CHANGED", "emits-changed" },
            { TP_DBUS_PROPERTIES_MIXIN_FLAG_EMITS_INVALIDATED, "TP_DBUS_PROPERTIES_MIXIN_FLAG_EMITS_INVALIDATED", "emits-invalidated" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("TpDBusPropertiesMixinFlags"), values);
    }
    return etype;
}

/* enumerations from "errors.h" */
#include "errors.h"

GType
tp_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { TP_ERROR_NETWORK_ERROR, "TP_ERROR_NETWORK_ERROR", "NetworkError" },
            { TP_ERROR_NOT_IMPLEMENTED, "TP_ERROR_NOT_IMPLEMENTED", "NotImplemented" },
            { TP_ERROR_INVALID_ARGUMENT, "TP_ERROR_INVALID_ARGUMENT", "InvalidArgument" },
            { TP_ERROR_NOT_AVAILABLE, "TP_ERROR_NOT_AVAILABLE", "NotAvailable" },
            { TP_ERROR_PERMISSION_DENIED, "TP_ERROR_PERMISSION_DENIED", "PermissionDenied" },
            { TP_ERROR_DISCONNECTED, "TP_ERROR_DISCONNECTED", "Disconnected" },
            { TP_ERROR_INVALID_HANDLE, "TP_ERROR_INVALID_HANDLE", "InvalidHandle" },
            { TP_ERROR_CHANNEL_BANNED, "TP_ERROR_CHANNEL_BANNED", "Channel.Banned" },
            { TP_ERROR_CHANNEL_FULL, "TP_ERROR_CHANNEL_FULL", "Channel.Full" },
            { TP_ERROR_CHANNEL_INVITE_ONLY, "TP_ERROR_CHANNEL_INVITE_ONLY", "Channel.InviteOnly" },
            { TP_ERROR_NOT_YOURS, "TP_ERROR_NOT_YOURS", "NotYours" },
            { TP_ERROR_CANCELLED, "TP_ERROR_CANCELLED", "Cancelled" },
            { TP_ERROR_AUTHENTICATION_FAILED, "TP_ERROR_AUTHENTICATION_FAILED", "AuthenticationFailed" },
            { TP_ERROR_ENCRYPTION_NOT_AVAILABLE, "TP_ERROR_ENCRYPTION_NOT_AVAILABLE", "EncryptionNotAvailable" },
            { TP_ERROR_ENCRYPTION_ERROR, "TP_ERROR_ENCRYPTION_ERROR", "EncryptionError" },
            { TP_ERROR_CERT_NOT_PROVIDED, "TP_ERROR_CERT_NOT_PROVIDED", "Cert.NotProvided" },
            { TP_ERROR_CERT_UNTRUSTED, "TP_ERROR_CERT_UNTRUSTED", "Cert.Untrusted" },
            { TP_ERROR_CERT_EXPIRED, "TP_ERROR_CERT_EXPIRED", "Cert.Expired" },
            { TP_ERROR_CERT_NOT_ACTIVATED, "TP_ERROR_CERT_NOT_ACTIVATED", "Cert.NotActivated" },
            { TP_ERROR_CERT_FINGERPRINT_MISMATCH, "TP_ERROR_CERT_FINGERPRINT_MISMATCH", "Cert.FingerprintMismatch" },
            { TP_ERROR_CERT_HOSTNAME_MISMATCH, "TP_ERROR_CERT_HOSTNAME_MISMATCH", "Cert.HostnameMismatch" },
            { TP_ERROR_CERT_SELF_SIGNED, "TP_ERROR_CERT_SELF_SIGNED", "Cert.SelfSigned" },
            { TP_ERROR_CERT_INVALID, "TP_ERROR_CERT_INVALID", "Cert.Invalid" },
            { TP_ERROR_NOT_CAPABLE, "TP_ERROR_NOT_CAPABLE", "NotCapable" },
            { TP_ERROR_OFFLINE, "TP_ERROR_OFFLINE", "Offline" },
            { TP_ERROR_CHANNEL_KICKED, "TP_ERROR_CHANNEL_KICKED", "Channel.Kicked" },
            { TP_ERROR_BUSY, "TP_ERROR_BUSY", "Busy" },
            { TP_ERROR_NO_ANSWER, "TP_ERROR_NO_ANSWER", "NoAnswer" },
            { TP_ERROR_DOES_NOT_EXIST, "TP_ERROR_DOES_NOT_EXIST", "DoesNotExist" },
            { TP_ERROR_TERMINATED, "TP_ERROR_TERMINATED", "Terminated" },
            { TP_ERROR_CONNECTION_REFUSED, "TP_ERROR_CONNECTION_REFUSED", "ConnectionRefused" },
            { TP_ERROR_CONNECTION_FAILED, "TP_ERROR_CONNECTION_FAILED", "ConnectionFailed" },
            { TP_ERROR_CONNECTION_LOST, "TP_ERROR_CONNECTION_LOST", "ConnectionLost" },
            { TP_ERROR_ALREADY_CONNECTED, "TP_ERROR_ALREADY_CONNECTED", "AlreadyConnected" },
            { TP_ERROR_CONNECTION_REPLACED, "TP_ERROR_CONNECTION_REPLACED", "ConnectionReplaced" },
            { TP_ERROR_REGISTRATION_EXISTS, "TP_ERROR_REGISTRATION_EXISTS", "RegistrationExists" },
            { TP_ERROR_SERVICE_BUSY, "TP_ERROR_SERVICE_BUSY", "ServiceBusy" },
            { TP_ERROR_RESOURCE_UNAVAILABLE, "TP_ERROR_RESOURCE_UNAVAILABLE", "ResourceUnavailable" },
            { TP_ERROR_WOULD_BREAK_ANONYMITY, "TP_ERROR_WOULD_BREAK_ANONYMITY", "WouldBreakAnonymity" },
            { TP_ERROR_CERT_REVOKED, "TP_ERROR_CERT_REVOKED", "Cert.Revoked" },
            { TP_ERROR_CERT_INSECURE, "TP_ERROR_CERT_INSECURE", "Cert.Insecure" },
            { TP_ERROR_CERT_LIMIT_EXCEEDED, "TP_ERROR_CERT_LIMIT_EXCEEDED", "Cert.LimitExceeded" },
            { TP_ERROR_NOT_YET, "TP_ERROR_NOT_YET", "NotYet" },
            { TP_ERROR_REJECTED, "TP_ERROR_REJECTED", "Rejected" },
            { TP_ERROR_PICKED_UP_ELSEWHERE, "TP_ERROR_PICKED_UP_ELSEWHERE", "PickedUpElsewhere" },
            { TP_ERROR_CONFUSED, "TP_ERROR_CONFUSED", "Confused" },
            { TP_ERROR_SERVICE_CONFUSED, "TP_ERROR_SERVICE_CONFUSED", "ServiceConfused" },
            { TP_ERROR_EMERGENCY_CALLS_NOT_SUPPORTED, "TP_ERROR_EMERGENCY_CALLS_NOT_SUPPORTED", "EmergencyCallsNotSupported" },
            { TP_ERROR_SOFTWARE_UPGRADE_REQUIRED, "TP_ERROR_SOFTWARE_UPGRADE_REQUIRED", "SoftwareUpgradeRequired" },
            { TP_ERROR_INSUFFICIENT_BALANCE, "TP_ERROR_INSUFFICIENT_BALANCE", "InsufficientBalance" },
            { TP_ERROR_MEDIA_CODECS_INCOMPATIBLE, "TP_ERROR_MEDIA_CODECS_INCOMPATIBLE", "Media.CodecsIncompatible" },
            { TP_ERROR_MEDIA_UNSUPPORTED_TYPE, "TP_ERROR_MEDIA_UNSUPPORTED_TYPE", "Media.UnsupportedType" },
            { TP_ERROR_MEDIA_STREAMING_ERROR, "TP_ERROR_MEDIA_STREAMING_ERROR", "Media.StreamingError" },
            { TP_ERROR_CAPTCHA_NOT_SUPPORTED, "TP_ERROR_CAPTCHA_NOT_SUPPORTED", "CaptchaNotSupported" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("TpError"), values);
    }
    return etype;
}

/* enumerations from "proxy.h" */
#include "proxy.h"

GType
tp_dbus_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { TP_DBUS_ERROR_UNKNOWN_REMOTE_ERROR, "TP_DBUS_ERROR_UNKNOWN_REMOTE_ERROR", "unknown-remote-error" },
            { TP_DBUS_ERROR_PROXY_UNREFERENCED, "TP_DBUS_ERROR_PROXY_UNREFERENCED", "proxy-unreferenced" },
            { TP_DBUS_ERROR_NO_INTERFACE, "TP_DBUS_ERROR_NO_INTERFACE", "no-interface" },
            { TP_DBUS_ERROR_NAME_OWNER_LOST, "TP_DBUS_ERROR_NAME_OWNER_LOST", "name-owner-lost" },
            { TP_DBUS_ERROR_INVALID_BUS_NAME, "TP_DBUS_ERROR_INVALID_BUS_NAME", "invalid-bus-name" },
            { TP_DBUS_ERROR_INVALID_INTERFACE_NAME, "TP_DBUS_ERROR_INVALID_INTERFACE_NAME", "invalid-interface-name" },
            { TP_DBUS_ERROR_INVALID_OBJECT_PATH, "TP_DBUS_ERROR_INVALID_OBJECT_PATH", "invalid-object-path" },
            { TP_DBUS_ERROR_INVALID_MEMBER_NAME, "TP_DBUS_ERROR_INVALID_MEMBER_NAME", "invalid-member-name" },
            { TP_DBUS_ERROR_OBJECT_REMOVED, "TP_DBUS_ERROR_OBJECT_REMOVED", "object-removed" },
            { TP_DBUS_ERROR_CANCELLED, "TP_DBUS_ERROR_CANCELLED", "cancelled" },
            { TP_DBUS_ERROR_INCONSISTENT, "TP_DBUS_ERROR_INCONSISTENT", "inconsistent" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("TpDBusError"), values);
    }
    return etype;
}


/* Generated data ends here */

