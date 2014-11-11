/* Auto-generated, do not edit.
 *
 * This file may be distributed under the same terms
 * as the specification from which it was generated.
 */

GType
mc_type_dbus_hash_su (void)
{
  static GType t = 0;

  if (G_UNLIKELY (t == 0))
    t = dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_UINT);
  return t;
}

GType
mc_type_dbus_array_of_a_7bsu_7d (void)
{
  static GType t = 0;

  if (G_UNLIKELY (t == 0))
    t = dbus_g_type_get_collection ("GPtrArray", mc_type_dbus_hash_su ());
  return t;
}

