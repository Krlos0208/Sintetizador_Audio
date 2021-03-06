
#include	<glib-object.h>


#ifdef G_ENABLE_DEBUG
#define g_marshal_value_peek_boolean(v)  g_value_get_boolean (v)
#define g_marshal_value_peek_char(v)     g_value_get_schar (v)
#define g_marshal_value_peek_uchar(v)    g_value_get_uchar (v)
#define g_marshal_value_peek_int(v)      g_value_get_int (v)
#define g_marshal_value_peek_uint(v)     g_value_get_uint (v)
#define g_marshal_value_peek_long(v)     g_value_get_long (v)
#define g_marshal_value_peek_ulong(v)    g_value_get_ulong (v)
#define g_marshal_value_peek_int64(v)    g_value_get_int64 (v)
#define g_marshal_value_peek_uint64(v)   g_value_get_uint64 (v)
#define g_marshal_value_peek_enum(v)     g_value_get_enum (v)
#define g_marshal_value_peek_flags(v)    g_value_get_flags (v)
#define g_marshal_value_peek_float(v)    g_value_get_float (v)
#define g_marshal_value_peek_double(v)   g_value_get_double (v)
#define g_marshal_value_peek_string(v)   (char*) g_value_get_string (v)
#define g_marshal_value_peek_param(v)    g_value_get_param (v)
#define g_marshal_value_peek_boxed(v)    g_value_get_boxed (v)
#define g_marshal_value_peek_pointer(v)  g_value_get_pointer (v)
#define g_marshal_value_peek_object(v)   g_value_get_object (v)
#define g_marshal_value_peek_variant(v)  g_value_get_variant (v)
#else /* !G_ENABLE_DEBUG */
/* WARNING: This code accesses GValues directly, which is UNSUPPORTED API.
 *          Do not access GValues directly in your code. Instead, use the
 *          g_value_get_*() functions
 */
#define g_marshal_value_peek_boolean(v)  (v)->data[0].v_int
#define g_marshal_value_peek_char(v)     (v)->data[0].v_int
#define g_marshal_value_peek_uchar(v)    (v)->data[0].v_uint
#define g_marshal_value_peek_int(v)      (v)->data[0].v_int
#define g_marshal_value_peek_uint(v)     (v)->data[0].v_uint
#define g_marshal_value_peek_long(v)     (v)->data[0].v_long
#define g_marshal_value_peek_ulong(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_int64(v)    (v)->data[0].v_int64
#define g_marshal_value_peek_uint64(v)   (v)->data[0].v_uint64
#define g_marshal_value_peek_enum(v)     (v)->data[0].v_long
#define g_marshal_value_peek_flags(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_float(v)    (v)->data[0].v_float
#define g_marshal_value_peek_double(v)   (v)->data[0].v_double
#define g_marshal_value_peek_string(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_param(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_boxed(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_pointer(v)  (v)->data[0].v_pointer
#define g_marshal_value_peek_object(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_variant(v)  (v)->data[0].v_pointer
#endif /* !G_ENABLE_DEBUG */


/* VOID:UINT,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:3) */
void
tp_ifaces_signals_marshal_VOID__UINT_STRING (GClosure     *closure,
                                             GValue       *return_value G_GNUC_UNUSED,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint G_GNUC_UNUSED,
                                             gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING) (gpointer     data1,
                                                  guint        arg_1,
                                                  gpointer     arg_2,
                                                  gpointer     data2);
  register GMarshalFunc_VOID__UINT_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}

/* VOID:UINT,BOXED,BOXED (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:5) */
void
tp_ifaces_signals_marshal_VOID__UINT_BOXED_BOXED (GClosure     *closure,
                                                  GValue       *return_value G_GNUC_UNUSED,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_BOXED_BOXED) (gpointer     data1,
                                                       guint        arg_1,
                                                       gpointer     arg_2,
                                                       gpointer     arg_3,
                                                       gpointer     data2);
  register GMarshalFunc_VOID__UINT_BOXED_BOXED callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_BOXED_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            data2);
}

/* VOID:STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:7) */

/* VOID:INT,BOXED (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:11) */
void
tp_ifaces_signals_marshal_VOID__INT_BOXED (GClosure     *closure,
                                           GValue       *return_value G_GNUC_UNUSED,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint G_GNUC_UNUSED,
                                           gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_BOXED) (gpointer     data1,
                                                gint         arg_1,
                                                gpointer     arg_2,
                                                gpointer     data2);
  register GMarshalFunc_VOID__INT_BOXED callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            data2);
}

/* VOID:UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:14) */

/* VOID:UINT,STRING,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:16) */
void
tp_ifaces_signals_marshal_VOID__UINT_STRING_STRING (GClosure     *closure,
                                                    GValue       *return_value G_GNUC_UNUSED,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint G_GNUC_UNUSED,
                                                    gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING_STRING) (gpointer     data1,
                                                         guint        arg_1,
                                                         gpointer     arg_2,
                                                         gpointer     arg_3,
                                                         gpointer     data2);
  register GMarshalFunc_VOID__UINT_STRING_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            data2);
}

/* VOID:UINT,UINT,UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:18) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT_UINT (GClosure     *closure,
                                                GValue       *return_value G_GNUC_UNUSED,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint G_GNUC_UNUSED,
                                                gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_UINT) (gpointer     data1,
                                                     guint        arg_1,
                                                     guint        arg_2,
                                                     guint        arg_3,
                                                     gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT_UINT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            data2);
}

/* VOID:BOOLEAN (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:20) */

/* VOID:UINT,UINT,UINT,UINT,UINT,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:22) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT_UINT_UINT_UINT_STRING (GClosure     *closure,
                                                                 GValue       *return_value G_GNUC_UNUSED,
                                                                 guint         n_param_values,
                                                                 const GValue *param_values,
                                                                 gpointer      invocation_hint G_GNUC_UNUSED,
                                                                 gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_UINT_UINT_UINT_STRING) (gpointer     data1,
                                                                      guint        arg_1,
                                                                      guint        arg_2,
                                                                      guint        arg_3,
                                                                      guint        arg_4,
                                                                      guint        arg_5,
                                                                      gpointer     arg_6,
                                                                      gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT_UINT_UINT_UINT_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 7);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_UINT_UINT_UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_uint (param_values + 4),
            g_marshal_value_peek_uint (param_values + 5),
            g_marshal_value_peek_string (param_values + 6),
            data2);
}

/* VOID:UINT,UINT,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:24) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT_STRING (GClosure     *closure,
                                                  GValue       *return_value G_GNUC_UNUSED,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_STRING) (gpointer     data1,
                                                       guint        arg_1,
                                                       guint        arg_2,
                                                       gpointer     arg_3,
                                                       gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 4);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_string (param_values + 3),
            data2);
}

/* VOID:UINT,UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:28) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT (GClosure     *closure,
                                           GValue       *return_value G_GNUC_UNUSED,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint G_GNUC_UNUSED,
                                           gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT) (gpointer     data1,
                                                guint        arg_1,
                                                guint        arg_2,
                                                gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            data2);
}

/* VOID:STRING,BOXED,BOXED,BOXED,BOXED,UINT,UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:30) */
void
tp_ifaces_signals_marshal_VOID__STRING_BOXED_BOXED_BOXED_BOXED_UINT_UINT (GClosure     *closure,
                                                                          GValue       *return_value G_GNUC_UNUSED,
                                                                          guint         n_param_values,
                                                                          const GValue *param_values,
                                                                          gpointer      invocation_hint G_GNUC_UNUSED,
                                                                          gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_BOXED_BOXED_BOXED_BOXED_UINT_UINT) (gpointer     data1,
                                                                               gpointer     arg_1,
                                                                               gpointer     arg_2,
                                                                               gpointer     arg_3,
                                                                               gpointer     arg_4,
                                                                               gpointer     arg_5,
                                                                               guint        arg_6,
                                                                               guint        arg_7,
                                                                               gpointer     data2);
  register GMarshalFunc_VOID__STRING_BOXED_BOXED_BOXED_BOXED_UINT_UINT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 8);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_BOXED_BOXED_BOXED_BOXED_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            g_marshal_value_peek_boxed (param_values + 4),
            g_marshal_value_peek_boxed (param_values + 5),
            g_marshal_value_peek_uint (param_values + 6),
            g_marshal_value_peek_uint (param_values + 7),
            data2);
}

/* VOID:BOXED (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:34) */

/* VOID:UINT,UINT,UINT,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:36) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT_UINT_STRING (GClosure     *closure,
                                                       GValue       *return_value G_GNUC_UNUSED,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_UINT_STRING) (gpointer     data1,
                                                            guint        arg_1,
                                                            guint        arg_2,
                                                            guint        arg_3,
                                                            gpointer     arg_4,
                                                            gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT_UINT_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_UINT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_string (param_values + 4),
            data2);
}

/* VOID:OBJECT,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:38) */
void
tp_ifaces_signals_marshal_VOID__OBJECT_STRING (GClosure     *closure,
                                               GValue       *return_value G_GNUC_UNUSED,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint G_GNUC_UNUSED,
                                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_STRING) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data2);
  register GMarshalFunc_VOID__OBJECT_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}

/* VOID:UINT,STRING,BOXED,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:40) */
void
tp_ifaces_signals_marshal_VOID__UINT_STRING_BOXED_STRING (GClosure     *closure,
                                                          GValue       *return_value G_GNUC_UNUSED,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint G_GNUC_UNUSED,
                                                          gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_STRING_BOXED_STRING) (gpointer     data1,
                                                               guint        arg_1,
                                                               gpointer     arg_2,
                                                               gpointer     arg_3,
                                                               gpointer     arg_4,
                                                               gpointer     data2);
  register GMarshalFunc_VOID__UINT_STRING_BOXED_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_STRING_BOXED_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            g_marshal_value_peek_boxed (param_values + 3),
            g_marshal_value_peek_string (param_values + 4),
            data2);
}

/* VOID:UINT,UINT,UINT,STRING,BOXED,UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:42) */
void
tp_ifaces_signals_marshal_VOID__UINT_UINT_UINT_STRING_BOXED_UINT (GClosure     *closure,
                                                                  GValue       *return_value G_GNUC_UNUSED,
                                                                  guint         n_param_values,
                                                                  const GValue *param_values,
                                                                  gpointer      invocation_hint G_GNUC_UNUSED,
                                                                  gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__UINT_UINT_UINT_STRING_BOXED_UINT) (gpointer     data1,
                                                                       guint        arg_1,
                                                                       guint        arg_2,
                                                                       guint        arg_3,
                                                                       gpointer     arg_4,
                                                                       gpointer     arg_5,
                                                                       guint        arg_6,
                                                                       gpointer     data2);
  register GMarshalFunc_VOID__UINT_UINT_UINT_STRING_BOXED_UINT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 7);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__UINT_UINT_UINT_STRING_BOXED_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_uint (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_string (param_values + 4),
            g_marshal_value_peek_boxed (param_values + 5),
            g_marshal_value_peek_uint (param_values + 6),
            data2);
}

/* VOID:OBJECT,UINT,UINT,UINT (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:44) */
void
tp_ifaces_signals_marshal_VOID__OBJECT_UINT_UINT_UINT (GClosure     *closure,
                                                       GValue       *return_value G_GNUC_UNUSED,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__OBJECT_UINT_UINT_UINT) (gpointer     data1,
                                                            gpointer     arg_1,
                                                            guint        arg_2,
                                                            guint        arg_3,
                                                            guint        arg_4,
                                                            gpointer     data2);
  register GMarshalFunc_VOID__OBJECT_UINT_UINT_UINT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 5);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__OBJECT_UINT_UINT_UINT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_object (param_values + 1),
            g_marshal_value_peek_uint (param_values + 2),
            g_marshal_value_peek_uint (param_values + 3),
            g_marshal_value_peek_uint (param_values + 4),
            data2);
}

/* VOID:STRING,BOXED (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:46) */
void
tp_ifaces_signals_marshal_VOID__STRING_BOXED (GClosure     *closure,
                                              GValue       *return_value G_GNUC_UNUSED,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint G_GNUC_UNUSED,
                                              gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_BOXED) (gpointer     data1,
                                                   gpointer     arg_1,
                                                   gpointer     arg_2,
                                                   gpointer     data2);
  register GMarshalFunc_VOID__STRING_BOXED callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_BOXED) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_boxed (param_values + 2),
            data2);
}

/* VOID:STRING,STRING (/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/work/armv7a-vfp-neon-poky-linux-gnueabi/libtelepathy/0.3.3-r5/libtelepathy-0.3.3/src/tp-ifaces-signals-marshal.list:48) */
void
tp_ifaces_signals_marshal_VOID__STRING_STRING (GClosure     *closure,
                                               GValue       *return_value G_GNUC_UNUSED,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint G_GNUC_UNUSED,
                                               gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__STRING_STRING) (gpointer     data1,
                                                    gpointer     arg_1,
                                                    gpointer     arg_2,
                                                    gpointer     data2);
  register GMarshalFunc_VOID__STRING_STRING callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__STRING_STRING) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_string (param_values + 1),
            g_marshal_value_peek_string (param_values + 2),
            data2);
}

