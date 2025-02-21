--- src/core/core-crypto.c.orig	2024-12-23 07:47:56 UTC
+++ src/core/core-crypto.c
@@ -40,6 +40,10 @@
 #define htobe64 OSSwapHostToBigInt64
 #endif
 
+#if defined __DragonFly__ || defined __MidnightBSD__
+#include <sys/endian.h>
+#endif
+
 #include "weechat.h"
 #include "core-crypto.h"
 #include "core-config-file.h"
