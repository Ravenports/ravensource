--- src/core/core-crypto.c.orig	2024-11-30 08:03:02 UTC
+++ src/core/core-crypto.c
@@ -37,6 +37,10 @@
 #include <endian.h>
 #endif
 
+#if defined __DragonFly__ || defined __MidnightBSD__
+#include <sys/endian.h>
+#endif
+
 #include "weechat.h"
 #include "core-crypto.h"
 #include "core-config-file.h"
