--- lib/vasnprintf.c.orig	2026-10-15 12:08:52 UTC
+++ lib/vasnprintf.c
@@ -285,7 +285,7 @@
 #define remainder rem
 
 #if (!USE_SNPRINTF || !HAVE_SNPRINTF_RETVAL_C99 || USE_MSVC__SNPRINTF || (PTRDIFF_MAX > INT_MAX)) && !WIDE_CHAR_VERSION
-# if (HAVE_STRNLEN && !defined _AIX)
+# if (HAVE_STRNLEN && !defined _AIX) && !defined(__sun__)
 #  define local_strnlen strnlen
 # else
 #  ifndef local_strnlen_defined
