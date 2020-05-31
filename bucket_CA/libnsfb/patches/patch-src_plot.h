--- src/plot.h.orig	2019-06-26 20:56:00 UTC
+++ src/plot.h
@@ -46,7 +46,11 @@
         #error "Endian determination failed"
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
