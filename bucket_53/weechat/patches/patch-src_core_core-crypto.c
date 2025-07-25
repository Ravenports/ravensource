--- src/core/core-crypto.c.orig	2025-07-19 10:01:43 UTC
+++ src/core/core-crypto.c
@@ -50,6 +50,10 @@
 #define BE_INT64 htobe64
 #endif
 
+#if defined __DragonFly__ || defined __MidnightBSD__
+#include <sys/endian.h>
+#endif
+
 #include "weechat.h"
 #include "core-crypto.h"
 #include "core-config-file.h"
