--- lib/util/gv_find_me.c.orig	2026-11-08 17:52:43 UTC
+++ lib/util/gv_find_me.c
@@ -13,8 +13,8 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 
 #if defined(_WIN32) && !defined(__CYGWIN__)
