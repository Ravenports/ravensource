Avoid collision with DragonFly's <unistd.h>

--- include/my_server_version.h.orig	2026-07-10 11:18:36 UTC
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
