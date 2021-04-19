--- lib/byteorder.h.orig	2021-04-14 03:02:50 UTC
+++ lib/byteorder.h
@@ -49,7 +49,7 @@
 
 #if defined(__linux__) || defined(__OpenBSD__)
 #  include <endian.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #endif
 
@@ -61,7 +61,7 @@
 #  define ntohll(x) (x)
 
 #else /* small-endian machines */
-#  if defined(__GNUC__) && __GNUC_PREREQ(4, 3)
+#  if defined(__GNUC__)
      /* Remove existing macros if present */
 #    undef ntohl
 #    undef htonl
