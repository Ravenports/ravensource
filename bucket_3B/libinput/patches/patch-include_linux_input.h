--- include/linux/input.h.orig	2025-03-24 03:54:25 UTC
+++ include/linux/input.h
@@ -1,5 +1,5 @@
 #ifdef __linux__
 #include "linux/input.h"
-#elif __FreeBSD__
+#elif defined __FreeBSD__ || defined __DragonFly__
 #include "freebsd/input.h"
 #endif
