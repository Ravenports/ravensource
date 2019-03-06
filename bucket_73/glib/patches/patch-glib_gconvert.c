Work around our situation of having both libiconv in libc and libiconv from
ports installed.

--- glib/gconvert.c.orig	2019-03-04 20:06:14 UTC
+++ glib/gconvert.c
@@ -56,7 +56,7 @@
 #error GNU libiconv in use but included iconv.h not from libiconv
 #endif
 #if !defined(USE_LIBICONV_GNU) && defined (_LIBICONV_H) \
-     && !defined (__APPLE_CC__) && !defined (__LP_64__)
+  && !defined (LIBICONV_PLUG) && !defined (__APPLE_CC__) && !defined (__LP_64__)
 #error GNU libiconv not in use but included iconv.h is from libiconv
 #endif
 
