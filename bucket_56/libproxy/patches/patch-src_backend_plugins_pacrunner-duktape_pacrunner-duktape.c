--- src/backend/plugins/pacrunner-duktape/pacrunner-duktape.c.orig	2024-07-19 19:33:22 UTC
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
