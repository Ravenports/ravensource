Avoid collision with DragonFly's <unistd.h>

--- include/my_server_version.h.orig	2026-11-06 09:09:05 UTC
+++ include/my_server_version.h
@@ -26,6 +26,13 @@
 
 #include "my_inttypes.h"  // uint
 
+#ifdef major
+#undef major
+#endif
+#ifdef minor
+#undef minor
+#endif
+
 struct My_server_version {
   uint version{0};
   bool is_lts{false};
