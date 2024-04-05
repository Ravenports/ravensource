--- src/backend/plugins/pacrunner-duktape/pacrunner-duktape.c.orig	2024-02-09 19:41:00 UTC
+++ src/backend/plugins/pacrunner-duktape/pacrunner-duktape.c
@@ -29,6 +29,10 @@
 #include <netinet/in.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#include <netinet/in.h>
+#endif
+
 #include "pacrunner-duktape.h"
 #include "pacutils.h"
 #include "px-plugin-pacrunner.h"
