--- src/util/sys_defs.h.orig	2024-02-06 17:02:38 UTC
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
