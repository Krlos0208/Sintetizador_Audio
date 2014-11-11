/*
 * tp-helpers.c - Source for various helper functions
 * for telepathy implementation
 *
 * Copyright (C) 2005-2007 Collabora Ltd. <http://www.collabora.co.uk/>
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

#include "tp-helpers.h"

#include <stdlib.h>
#include <string.h>

#include <dbus/dbus-glib.h>

#include "tp-connmgr-signals-marshal.h"
#include "tp-conn-signals-marshal.h"
#include "tp-chan-signals-marshal.h"
#include "tp-ifaces-signals-marshal.h"
#include "_gen/register-marshallers.h"


#define CM_CONFS_DIR   "/telepathy/managers/"
#define CM_CONF_SUFFIX ".manager"
#define CM_CONF_GROUP "ConnectionManager"


void
_tp_warn_failure (const char *op, GError *error)
{
  if (error == NULL)
    {
      g_warning ("%s failed: error is NULL", op);
    }
  else if (error->domain == DBUS_GERROR
      && error->code == DBUS_GERROR_REMOTE_EXCEPTION)
    {
      g_warning ("%s failed: %s (%s)", op, error->message,
          dbus_g_error_get_name (error));
    }
  else
    {
      g_warning ("%s failed: %s (%s code %d)", op, error->message,
          g_quark_to_string (error->domain), error->code);
    }
}

static void
_list_builder (gpointer key,
               gpointer value,
               gpointer data)
{
  GSList **list = (GSList **) data;
  TpKeyValue *kv = g_new0 (TpKeyValue, 1);

  kv->key = key;
  kv->value = value;
  *list = g_slist_prepend (*list, kv);
}

GSList *
tp_hash_to_key_value_list (GHashTable *hash)
{
  GSList *ret = NULL;

  g_hash_table_foreach (hash, _list_builder, &ret);
  return ret;
}

void
tp_key_value_list_free (GSList *list)
{
  GSList *iter;

  for (iter = list; iter; iter = g_slist_next (iter))
    {
      g_free (iter->data);
    }

  g_slist_free (list);
}

static void
_scan_dir (GSList **cmgr_list, const gchar *path)
{
  GDir *dir;
  const gchar *filename;

  if ((dir = g_dir_open (path, 0, NULL)) == NULL)
    return;

  while ((filename = g_dir_read_name (dir)) != NULL)
    {
      if (g_str_has_suffix (filename, CM_CONF_SUFFIX))
      {
        gchar **name;

        name = g_strsplit (filename, ".", 0);
        *cmgr_list = g_slist_append (*cmgr_list, g_strdup (*name));
        g_strfreev (name);
      }
    }

  g_dir_close (dir);
}

GSList *
tp_connmgr_list_cms (void)
{
  GSList *cmgr_list = NULL;
  const gchar * const *data_dirs;
  gchar *path;
  gint index;

  /* Read the configuration file directory */
  path = g_build_filename (g_get_user_data_dir (), CM_CONFS_DIR, NULL);
  _scan_dir (&cmgr_list, path);
  g_free (path);

  data_dirs = g_get_system_data_dirs ();
  for (index = 0; data_dirs[index] != NULL; index++)
  {
    path = g_build_filename (data_dirs[index], CM_CONFS_DIR, NULL);
    _scan_dir (&cmgr_list, path);
    g_free (path);
  }

  return cmgr_list;
}

static void
_prot_param_free (TpConnMgrProtParam *param)
{
  g_free (param->dbus_type);
  g_free (param->default_value);
  g_slice_free (TpConnMgrProtParam, param);
}

TpConnMgrInfo *
tp_connmgr_get_info (const gchar *cm)
{
  GError *error = NULL;
  GKeyFile *file;
  gchar *absolute_filepath;
  gchar *home_dir_confs;
  gchar **groups, **group;
  TpConnMgrInfo *cm_info;

  home_dir_confs = g_build_filename (g_get_user_data_dir (), CM_CONFS_DIR,
      NULL);
  absolute_filepath = g_strconcat (home_dir_confs, cm, CM_CONF_SUFFIX, NULL);
  g_free (home_dir_confs);

  if (!g_file_test (absolute_filepath, G_FILE_TEST_EXISTS))
    {
      gint  index;
      gchar *dir_confs;
      const gchar * const *data_dirs;

      g_free (absolute_filepath);
      absolute_filepath = NULL;

      data_dirs = g_get_system_data_dirs ();
      for (index = 0;
           data_dirs[index] != NULL && absolute_filepath == NULL;
           index++)
        {
          dir_confs = g_build_filename (data_dirs[index], CM_CONFS_DIR, NULL);
          absolute_filepath = g_strconcat (dir_confs, cm, CM_CONF_SUFFIX,
              NULL);
          g_free (dir_confs);

          if (!g_file_test (absolute_filepath, G_FILE_TEST_EXISTS))
            {
              g_free (absolute_filepath);
              absolute_filepath = NULL;
            }
        }

      if (absolute_filepath == NULL)
        {
          g_warning ("Could not open configuration file for:'%s'", cm);
          return NULL;
        }
    }

  cm_info = g_slice_new0 (TpConnMgrInfo);
  cm_info->protocols = g_hash_table_new_full (g_str_hash, g_str_equal, g_free,
      (GDestroyNotify) g_hash_table_destroy);

  file = g_key_file_new ();

  if (!g_key_file_load_from_file
      (file, absolute_filepath, G_KEY_FILE_NONE, &error))
    {
      /* handle error */
      g_printerr ("%s", error->message);
      g_error_free (error);
      g_free (absolute_filepath);
      g_key_file_free (file);
      tp_connmgr_info_free (cm_info);
      return NULL;
    }

  g_free (absolute_filepath);

  cm_info->name = g_strdup (cm);
  cm_info->bus_name = g_key_file_get_string (file, CM_CONF_GROUP, "BusName",
      &error);

  if (cm_info->bus_name == NULL)
    {
      /* handle error and free dynamic memory */
      g_printerr ("%s", error->message);
      g_error_free (error);
      g_key_file_free (file);
      tp_connmgr_info_free (cm_info);
      return NULL;
    }

  cm_info->object_path = g_key_file_get_string (file, CM_CONF_GROUP,
      "ObjectPath", &error);

  if (cm_info->object_path == NULL)
    {
      /* handle error and free dynamic memory */
      g_printerr ("%s", error->message);
      g_error_free (error);
      g_key_file_free (file);
      tp_connmgr_info_free (cm_info);
      return NULL;
    }

  groups = g_key_file_get_groups (file, NULL);

  /* FIXME: this assumes the first group in the file is CM_CONF_GROUP */

  for (group = groups + 1; *group; group++)
    {
      gchar **keys, **key;
      gchar *prot_name;
      GHashTable *params;

      if (!g_str_has_prefix (*group, "Protocol "))
        continue;

      params = g_hash_table_new_full (g_str_hash, g_str_equal, g_free,
                                      (GDestroyNotify)_prot_param_free);
      keys = g_strsplit (*group, " ", 2);
      prot_name = g_strdup (keys[1]);
      g_strfreev (keys);
      g_hash_table_insert (cm_info->protocols, prot_name, params);

      keys = g_key_file_get_keys (file, *group, NULL, &error);

      if (keys == NULL)
        {
          g_printerr ("%s", error->message);
          g_error_free (error);
          continue;
        }

      for (key = keys; *key; key++)
        {
          gchar **strv;
          gchar *param_name;
          gchar *key_value;
          TpConnMgrProtParam *param;

          if (!g_str_has_prefix (*key, "param-") &&
              !g_str_has_prefix (*key, "default-"))
            {
              g_printerr ("invalid protocol key");
              continue;
            }

          key_value = g_key_file_get_string (file, *group, *key, &error);

          if (key_value == NULL)
            {
              g_printerr ("%s", error->message);
              g_error_free (error);
              continue;
            }

          strv = g_strsplit (*key, "-", 2);
          param_name = g_strdup (strv[1]);
          param = g_hash_table_lookup (params, param_name);
          if (param == NULL)
            {
              param = g_slice_new0 (TpConnMgrProtParam);
              g_hash_table_insert (params, param_name, param);
            }
          else
            {
              g_free (param_name);
            }

          if (strcmp (strv[0], "param") == 0)
            {
              gchar **flags, **f;

              flags = g_strsplit (key_value, " ", 0);
              g_free (key_value);
              param->dbus_type = g_strdup (flags[0]);

              for (f = flags + 1; *f; f++)
                {
                  if (strcmp (*f, "required") == 0)
                    param->flags |= TP_CONN_MGR_PARAM_FLAG_REQUIRED;
                  else if (strcmp (*f, "register") == 0)
                    param->flags |= TP_CONN_MGR_PARAM_FLAG_REGISTER;
                }

              g_strfreev (flags);
            }
          else if (strcmp (strv[0], "default") == 0)
            {
              param->default_value = key_value;
              param->flags |= TP_CONN_MGR_PARAM_FLAG_HAS_DEFAULT;
            }
          else
            {
                g_printerr ("invalid param key:%s", *key);
                g_free (key_value);
                g_strfreev (strv);
                continue;
            }

          g_strfreev (strv);
        }

      g_strfreev (keys);
    }

  g_strfreev (groups);
  g_key_file_free (file);
  return cm_info;
}

void
tp_connmgr_info_free (TpConnMgrInfo *info)
{
  if (info == NULL)
    return;

  g_free (info->name);
  g_free (info->bus_name);
  g_free (info->object_path);

  if (info->protocols != NULL)
    g_hash_table_destroy (info->protocols);

  g_slice_free (TpConnMgrInfo, info);
}

void
_tp_register_marshallers (void)
{
  gboolean done = FALSE;

  if (!done)
    {
      REGISTER_ALL_MARSHALLERS;
      done = TRUE;
    }
}
