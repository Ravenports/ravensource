--- glib/gconvert.c.orig	2025-02-21 14:08:33 UTC
+++ glib/gconvert.c
@@ -182,13 +182,6 @@ g_iconv_open (const gchar  *to_codeset,
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
  * Returns: count of non-reversible conversions, or -1 on error
  **/
 gsize 
@@ -297,14 +290,6 @@ close_converter (GIConv cd)
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
@@ -384,13 +369,6 @@ g_convert_with_iconv (const gchar *str,
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
