Revert https://gitlab.gnome.org/GNOME/glib/commit/8abf3a04e699 for
breaking at least graphics/inkscape as wchar_t is locale-dependent.

--- glib/gconvert.c.orig	2025-09-05 12:42:14 UTC
+++ glib/gconvert.c
@@ -69,7 +69,7 @@ try_conversion (const char *to_codeset,
   if (*cd == (iconv_t)-1 && errno == EINVAL)
     return FALSE;
 
-#if defined(__FreeBSD__) && defined(ICONV_SET_ILSEQ_INVALID)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(ICONV_SET_ILSEQ_INVALID)
   /* On FreeBSD request GNU iconv compatible handling of characters that cannot
    * be represented in the destination character set.
    * See https://cgit.freebsd.org/src/commit/?id=7c5b23111c5fd1992047922d4247c4a1ce1bb6c3
@@ -121,6 +121,18 @@ g_iconv_open (const gchar  *to_codeset,
 	      const gchar  *from_codeset)
 {
   iconv_t cd;
+#if defined __NetBSD__
+  {
+    const char * nbsd_new_codeset;
+    const char * nbsd_old_codeset;
+
+    nbsd_new_codeset = (strcmp(to_codeset, "646")) ? to_codeset : "ASCII";
+    nbsd_old_codeset = (strcmp(from_codeset, "646")) ? from_codeset : "ASCII";
+
+   if (try_conversion (nbsd_new_codeset, nbsd_old_codeset, &cd))
+      goto out;
+  }
+#endif
   
   if (!try_conversion (to_codeset, from_codeset, &cd))
     {
@@ -165,13 +177,6 @@ g_iconv_open (const gchar  *to_codeset,
  * GLib provides g_convert() and g_locale_to_utf8() which are likely
  * more convenient than the raw iconv wrappers.
  * 
- * Note that the behaviour of iconv() for characters which are valid in the
- * input character set, but which have no representation in the output character
- * set, is implementation defined. This function may return success (with a
- * positive number of non-reversible conversions as replacement characters were
- * used), or it may return -1 and set an error such as %EILSEQ, in such a
- * situation.
- *
  * See [`iconv(3posix)`](man:iconv(3posix)) and [`iconv(3)`](man:iconv(3)) for more details about behavior when an
  * error occurs.
  *
@@ -283,14 +288,6 @@ close_converter (GIConv cd)
  * character until it knows that the next character is not a mark that
  * could combine with the base character.)
  *
- * Characters which are valid in the input character set, but which have no
- * representation in the output character set will result in a
- * %G_CONVERT_ERROR_ILLEGAL_SEQUENCE error. This is in contrast to the iconv()
- * specification, which leaves this behaviour implementation defined. Note that
- * this is the same error code as is returned for an invalid byte sequence in
- * the input character set. To get defined behaviour for conversion of
- * unrepresentable characters, use g_convert_with_fallback().
- *
  * Returns: (array length=bytes_written) (element-type guint8) (transfer full):
  *               If the conversion was successful, a newly allocated buffer
  *               containing the converted string, which must be freed with
@@ -370,13 +367,6 @@ g_convert_with_iconv (const gchar *str,
 	      break;
 	    }
 	}
-      else if (err > 0)
-        {
-          /* @err gives the number of replacement characters used. */
-          g_set_error_literal (error, G_CONVERT_ERROR, G_CONVERT_ERROR_ILLEGAL_SEQUENCE,
-                               _("Unrepresentable character in conversion input"));
-          have_error = TRUE;
-        }
       else 
 	{
 	  if (!reset)
