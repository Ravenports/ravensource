--- include/linux/input.h.orig	2026-04-02 01:04:12 UTC
+++ include/linux/input.h
@@ -1,5 +1,5 @@
 #ifdef __linux__
 #include "linux/input.h"
-#elif __FreeBSD__
+#elif defined __FreeBSD__ || defined __DragonFly__
 #include "freebsd/input.h"
 #endif
