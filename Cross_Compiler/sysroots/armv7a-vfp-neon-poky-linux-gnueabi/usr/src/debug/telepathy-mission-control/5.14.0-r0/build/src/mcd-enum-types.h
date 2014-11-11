


#ifndef __MCD_ENUM_TYPES_H__
#define __MCD_ENUM_TYPES_H__

#include "mcd-mission.h"
#include "mcd-channel.h"
#include "mcd-transport.h"

G_BEGIN_DECLS
/* enumerations from "mcd-account.h" */
GType mcd_account_error_get_type (void) G_GNUC_CONST;
#define MCD_TYPE_ACCOUNT_ERROR (mcd_account_error_get_type())
/* enumerations from "mcd-channel.h" */
GType mcd_channel_status_get_type (void) G_GNUC_CONST;
#define MCD_TYPE_CHANNEL_STATUS (mcd_channel_status_get_type())
/* enumerations from "mcd-transport.h" */
GType mcd_transport_status_get_type (void) G_GNUC_CONST;
#define MCD_TYPE_TRANSPORT_STATUS (mcd_transport_status_get_type())
G_END_DECLS

#endif /* __MCD_ENUM_TYPES_H__ */



