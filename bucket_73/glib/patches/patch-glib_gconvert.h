Revert https://gitlab.gnome.org/GNOME/glib/commit/8abf3a04e699 for
breaking at least graphics/inkscape as wchar_t is locale-dependent.

--- glib/gconvert.h.orig	2025-09-05 12:42:14 UTC
+++ glib/gconvert.h
@@ -39,9 +39,7 @@ G_BEGIN_DECLS
  * GConvertError:
  * @G_CONVERT_ERROR_NO_CONVERSION: Conversion between the requested character
  *     sets is not supported.
- * @G_CONVERT_ERROR_ILLEGAL_SEQUENCE: Invalid byte sequence in conversion input;
- *    or the character sequence could not be represented in the target
- *    character set.
+ * @G_CONVERT_ERROR_ILLEGAL_SEQUENCE: Invalid byte sequence in conversion input.
  * @G_CONVERT_ERROR_FAILED: Conversion failed for some reason.
  * @G_CONVERT_ERROR_PARTIAL_INPUT: Partial character sequence at end of input.
  * @G_CONVERT_ERROR_BAD_URI: URI is invalid.
