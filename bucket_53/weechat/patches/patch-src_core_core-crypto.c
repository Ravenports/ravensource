--- src/core/core-crypto.c.orig	2024-09-08 09:49:21 UTC
+++ src/core/core-crypto.c
@@ -31,6 +31,10 @@
 #include <math.h>
 #include <gcrypt.h>
 
+#if defined __DragonFly__
+#include <sys/endian.h>
+#endif
+
 #include "weechat.h"
 #include "core-crypto.h"
 #include "core-config-file.h"
