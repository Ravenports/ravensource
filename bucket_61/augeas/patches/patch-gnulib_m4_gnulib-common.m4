--- gnulib/m4/gnulib-common.m4.orig	2021-01-26 16:36:05 UTC
+++ gnulib/m4/gnulib-common.m4
@@ -226,11 +226,7 @@ AC_DEFUN([gl_COMMON_BODY], [
 # define _GL_ATTRIBUTE_NOINLINE
 #endif
 
-#if _GL_HAS_ATTRIBUTE (nonnull)
-# define _GL_ATTRIBUTE_NONNULL(args) __attribute__ ((__nonnull__ args))
-#else
 # define _GL_ATTRIBUTE_NONNULL(args)
-#endif
 
 #if _GL_HAS_ATTRIBUTE (nonstring)
 # define _GL_ATTRIBUTE_NONSTRING __attribute__ ((__nonstring__))
