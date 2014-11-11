/*
 * Copyright (C) 2007 Collabora Ltd.
 * Copyright (C) 2007 Nokia Corporation
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

#ifndef __TELEPATHY_INTERNAL_H__
#define __TELEPATHY_INTERNAL_H__

#include <glib.h>

G_BEGIN_DECLS

void _tp_warn_failure (const char *op, GError *error);
void _tp_register_marshallers (void);
void _tp_conn_connect_req_handler (DBusGProxy *proxy, GError *error,
    gpointer user_data);

G_END_DECLS

#endif /* __TELEPATHY_INTERNAL_H__ */
