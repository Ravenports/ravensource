--- src/util/sys_defs.h.orig	2025-01-03 18:19:26 UTC
+++ src/util/sys_defs.h
@@ -35,10 +35,7 @@
     || defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
     || defined(OPENBSD2) || defined(OPENBSD3) || defined(OPENBSD4) \
     || defined(OPENBSD5) || defined(OPENBSD6) || defined(OPENBSD7) \
-    || defined(NETBSD1) || defined(NETBSD2) || defined(NETBSD3) \
-    || defined(NETBSD4) || defined(NETBSD5) || defined(NETBSD6) \
-    || defined(NETBSD7) | defined(NETBSD8) || defined(NETBSD9) \
-    || defined(NETBSD10) \
+    || defined(NETBSD) \
     || defined(EKKOBSD1) || defined(DRAGONFLY)
 #define SUPPORTED
 #include <sys/param.h>
@@ -174,7 +171,7 @@
 #endif
 
 #if defined(__DragonFly__)
-#define HAS_DEV_URANDOM
+#define HAS_CLOSEFROM
 #define HAS_ISSETUGID
 #define HAS_FUTIMES
 #define SOCKADDR_SIZE	socklen_t
