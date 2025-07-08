--- lib/vasnprintf.c.orig	2024-09-11 23:03:55 UTC
+++ lib/vasnprintf.c
@@ -233,7 +233,7 @@
 #define remainder rem
 
 #if (!USE_SNPRINTF || !HAVE_SNPRINTF_RETVAL_C99 || USE_MSVC__SNPRINTF || (PTRDIFF_MAX > INT_MAX)) && !WIDE_CHAR_VERSION
-# if (HAVE_STRNLEN && !defined _AIX)
+# if (HAVE_STRNLEN && !defined _AIX) && !defined(__sun__)
 #  define local_strnlen strnlen
 # else
 #  ifndef local_strnlen_defined
