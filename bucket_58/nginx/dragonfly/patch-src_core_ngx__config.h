--- src/core/ngx_config.h.orig	2025-06-24 17:22:41 UTC
+++ src/core/ngx_config.h
@@ -12,8 +12,8 @@
 #include <ngx_auto_headers.h>
 
 
-#if defined __DragonFly__ && !defined __FreeBSD__
-#define __FreeBSD__        4
+#if defined __DragonFly__
+#undef  __FreeBSD_version
 #define __FreeBSD_version  480101
 #endif
 
