/* tp-props-iface.h
 *
 * Copyright (C) 2005,2006 Nokia Corporation.
 * Copyright (C) 2006 Collabora Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef LIBTELEPATHY_PROPS_IFACE_H
#define LIBTELEPATHY_PROPS_IFACE_H

#ifndef DBUS_API_SUBJECT_TO_CHANGE
#define DBUS_API_SUBJECT_TO_CHANGE
#endif

#include <dbus/dbus-glib.h>

#include "tp-constants.h"
#include "tp-interfaces.h"
#include "tp-props-iface-gen.h"

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED
#define TELEPATHY_PROPS_IFACE_QUARK TP_IFACE_QUARK_PROPERTIES_INTERFACE
#endif

typedef struct _TpPropsIface TpPropsIface;
typedef struct _TpPropsIfaceClass TpPropsIfaceClass;

struct _TpPropsIface
{
  DBusGProxy parent;
  gpointer priv;
};

struct _TpPropsIfaceClass
{
  DBusGProxyClass parent_class;
};

GType tp_props_iface_get_type (void);

#define TELEPATHY_PROPS_IFACE_TYPE (tp_props_iface_get_type ())

#define TELEPATHY_PROPS_IFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST \
                                   ((obj), TELEPATHY_PROPS_IFACE_TYPE, \
                                    TpPropsIface))

#define TELEPATHY_PROPS_IFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST \
                                     ((klass), TELEPATHY_PROPS_IFACE_TYPE, \
                                      TpPropsIfaceClass))

#define TELEPATHY_IS_PROPS_IFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE \
                                ((obj), TELEPATHY_PROPS_IFACE_TYPE))

#define TELEPATHY_IS_PROPS_IFACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
                                        ((klass), TELEPATHY_PROPS_IFACE_TYPE))

#define TELEPATHY_PROPS_IFACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS \
                                       ((obj), TELEPATHY_PROPS_IFACE_TYPE, \
                                        TpPropsIfaceClass))

/**
 * TpPropsChangedFlags:
 * @TP_PROPS_CHANGED_VALUE: The value of the property changed.
 * @TP_PROPS_CHANGED_FLAGS: The flags of the property changed.
 */
typedef enum
{
  TP_PROPS_CHANGED_VALUE = 0x01,
  TP_PROPS_CHANGED_FLAGS = 0x02
} TpPropsChanged;

TpPropsIface * tp_props_iface_new (DBusGConnection *connection,
    const char *name, const char *path_name);

void tp_props_iface_set_mapping (TpPropsIface *iface,
    const gchar *first_name, ...) G_GNUC_NULL_TERMINATED;
gboolean tp_props_iface_get_value (TpPropsIface* iface, guint prop_id,
    GValue *return_value);

gboolean tp_props_iface_set_value (TpPropsIface* iface, guint prop_id,
    const GValue *value);

TpPropertyFlags tp_props_iface_property_flags (TpPropsIface* iface,
    guint prop_id);

#ifndef LIBTELEPATHY_DISABLE_DEPRECATED
GQuark tp_get_props_interface (void) G_GNUC_DEPRECATED;
#endif

void tp_props_interface_set_signatures (DBusGProxy *proxy);
#endif
