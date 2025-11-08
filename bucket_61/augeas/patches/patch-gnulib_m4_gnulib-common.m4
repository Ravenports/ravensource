--- gnulib/m4/gnulib-common.m4.orig	2023-07-14 23:39:14 UTC
+++ gnulib/m4/gnulib-common.m4
@@ -345,11 +345,7 @@ AC_DEFUN([gl_COMMON_BODY], [
    _GL_ATTRIBUTE_NONNULL () declares that all pointer arguments must not be
    null.  */
 /* Applies to: functions.  */
-#if _GL_HAS_ATTRIBUTE (nonnull)
-# define _GL_ATTRIBUTE_NONNULL(args) __attribute__ ((__nonnull__ args))
-#else
 # define _GL_ATTRIBUTE_NONNULL(args)
-#endif
 
 /* _GL_ATTRIBUTE_NONSTRING declares that the contents of a character array is
    not meant to be NUL-terminated.  */
