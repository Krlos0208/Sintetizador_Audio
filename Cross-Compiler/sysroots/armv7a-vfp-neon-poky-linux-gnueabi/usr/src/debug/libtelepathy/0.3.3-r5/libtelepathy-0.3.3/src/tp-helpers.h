/*
 * tp-helpers.h - Header for various helper functions
 * for telepathy implementation
 * Copyright (C) 2005 Collabora Ltd.
 * Copyright (C) 2005 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __LIBTELEPATHY_HELPERS_H__
#define __LIBTELEPATHY_HELPERS_H__

#include <glib.h>
#include <dbus/dbus-glib.h>

#include "tp-constants.h"

G_BEGIN_DECLS

typedef struct
{
  gpointer key;
  gpointer value;
} TpKeyValue;

DBusGConnection *tp_get_bus (void);
DBusGProxy *tp_get_bus_proxy (void);
GSList *tp_hash_to_key_value_list (GHashTable *hashtable);
void tp_key_value_list_free (GSList *list);

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED

#define TP_CONNMGR_PROT_PARAM_FLAG_REQUIRED (TP_CONN_MGR_PARAM_FLAG_REQUIRED)
#define TP_CONNMGR_PROT_PARAM_FLAG_REGISTER (TP_CONN_MGR_PARAM_FLAG_REGISTER)
#define TP_CONNMGR_PROT_PARAM_FLAG_HAS_DEFAULT \
  (TP_CONN_MGR_PARAM_FLAG_HAS_DEFAULT)
#define TpConnMgrProtParamFlag TpConnMgrParamFlags

#endif

typedef struct _tp_connmgr_info TpConnMgrInfo;
typedef struct _tp_connmgr_protocol_param TpConnMgrProtParam;

struct _tp_connmgr_protocol_param
{
  TpConnMgrParamFlags flags;
  gchar *default_value;
  gchar *dbus_type;
};

struct _tp_connmgr_info
{
  gchar *name;
  gchar *bus_name;
  gchar *object_path;

  /* protocol_name<->(param_name<->TpConnMgrProtParam) */
  GHashTable *protocols;
};

/*
 * Lists all the connection manager files.
 *
 * Please use tp_list_connection_managers() from telepathy-glib instead:
 * it uses a more correct procedure.
 *
 * @return A list of connection manager names
 */
GSList *tp_connmgr_list_cms (void);

/*
 * Returns the connection manager information for the given connection manager
 * @param cm: the connection manager name string
 * @return A struct containing all the information read from the connection
 * manager file.
 */
TpConnMgrInfo *tp_connmgr_get_info (const gchar *cm);

void tp_connmgr_info_free (TpConnMgrInfo *info);

G_END_DECLS

#endif /* __TELEPATHY_HELPERS_H__ */

