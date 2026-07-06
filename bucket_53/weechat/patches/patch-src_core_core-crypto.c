--- src/core/core-crypto.c.orig	2026-06-07 07:25:09 UTC
+++ src/core/core-crypto.c
@@ -53,6 +53,10 @@
 #define BE_INT64 htobe64
 #endif
 
+#if defined __DragonFly__ || defined __MidnightBSD__
+#include <sys/endian.h>
+#endif
+
 #include "weechat.h"
 #include "core-crypto.h"
 #include "core-config-file.h"
