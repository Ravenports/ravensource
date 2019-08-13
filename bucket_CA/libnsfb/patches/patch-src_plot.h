--- src/plot.h.orig	2018-08-28 09:33:35 UTC
+++ src/plot.h
@@ -36,7 +36,11 @@
         #define NSFB_BE_BYTE_ORDER
     #endif
 #else
+# if defined(__DragonFly__) || defined(__FreeBSD__)
+    #include <sys/endian.h>
+#else
     #include <endian.h>
+#endif
     #if defined(__BYTE_ORDER__)
         #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
             #define NSFB_BE_BYTE_ORDER
