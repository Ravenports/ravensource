--- lib/util/gv_find_me.c.orig	2025-12-13 19:25:47 UTC
+++ lib/util/gv_find_me.c
@@ -9,8 +9,8 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 
 #if defined(_WIN32) && !defined(__CYGWIN__)
