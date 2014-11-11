/* Auto-generated, do not edit.
 *
 * This file may be distributed under the same terms
 * as the specification from which it was generated.
 */

/**
 * MC_HASH_TYPE_ACCOUNT_FLAGS_MAP:
 *
 * A mapping from Account_Ids to account flags.
 *
 * This macro expands to a call to a function
 * that returns the #GType of a #GHashTable
 * appropriate for representing a D-Bus
 * dictionary of signature
 * <literal>a{su}</literal>.
 *
 * Keys (D-Bus type <literal>s</literal>,
 * named <literal>Account_Id</literal>):
 * (Undocumented)
 *
 * Values (D-Bus type <literal>u</literal>,
 * type <literal>Account_Flags</literal>,
 * named <literal>Flags</literal>):
 * (Undocumented)
 *
 */
#define MC_HASH_TYPE_ACCOUNT_FLAGS_MAP (mc_type_dbus_hash_su ())

/**
 * MC_ARRAY_TYPE_ACCOUNT_FLAGS_MAP_LIST:

 * Expands to a call to a function
 * that returns the #GType of a #GPtrArray
 * of #MC_HASH_TYPE_ACCOUNT_FLAGS_MAP.
 */
#define MC_ARRAY_TYPE_ACCOUNT_FLAGS_MAP_LIST (mc_type_dbus_array_of_a_7bsu_7d ())

GType mc_type_dbus_hash_su (void);

GType mc_type_dbus_array_of_a_7bsu_7d (void);

