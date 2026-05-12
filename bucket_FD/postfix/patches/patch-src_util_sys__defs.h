--- src/util/sys_defs.h.orig	2026-05-01 18:55:47 UTC
+++ src/util/sys_defs.h
@@ -36,10 +36,7 @@
     || defined(OPENBSD2) || defined(OPENBSD3) || defined(OPENBSD4) \
     || defined(OPENBSD5) || defined(OPENBSD6) || defined(OPENBSD7) \
     || defined(OPENBSD8) \
-    || defined(NETBSD1) || defined(NETBSD2) || defined(NETBSD3) \
-    || defined(NETBSD4) || defined(NETBSD5) || defined(NETBSD6) \
-    || defined(NETBSD7) | defined(NETBSD8) || defined(NETBSD9) \
-    || defined(NETBSD10) || defined(NETBSD11) || defined(NETBSD12) \
+    || defined(NETBSD) \
     || defined(EKKOBSD1) || defined(DRAGONFLY)
 #define SUPPORTED
 #include <sys/param.h>
@@ -175,7 +172,7 @@
 #endif
 
 #if defined(__DragonFly__)
-#define HAS_DEV_URANDOM
+#define HAS_CLOSEFROM
 #define HAS_ISSETUGID
 #define HAS_FUTIMES
 #define SOCKADDR_SIZE	socklen_t
