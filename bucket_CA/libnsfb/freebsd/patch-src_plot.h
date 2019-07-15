--- src/plot.h.orig	2019-07-15 17:56:47.685315000 +0200
+++ src/plot.h	2019-07-15 17:58:00.645754000 +0200
@@ -36,7 +36,7 @@
         #define NSFB_BE_BYTE_ORDER
     #endif
 #else
-    #include <endian.h>
+    #include <sys/endian.h>
     #if defined(__BYTE_ORDER__)
         #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
             #define NSFB_BE_BYTE_ORDER
