void
_mcd_ext_register_dbus_glib_marshallers (void)
{
  dbus_g_object_register_marshaller (_mcd_ext_marshal_VOID__BOXED_BOOLEAN,
      G_TYPE_NONE,       /* return */
      G_TYPE_BOXED,
      G_TYPE_BOOLEAN,
      G_TYPE_INVALID);
  dbus_g_object_register_marshaller (g_cclosure_marshal_VOID__BOXED,
      G_TYPE_NONE,       /* return */
      G_TYPE_BOXED,
      G_TYPE_INVALID);
}
