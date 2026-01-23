* define ppoll on older NetBSD that only has pollts

--- vio/viosocket.cc.orig	2025-12-15 13:32:53 UTC
+++ vio/viosocket.cc
@@ -92,6 +92,13 @@
 
 struct timespec;
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if !__NetBSD_Prereq__(9,99,71)
+#define ppoll pollts
+#endif
+#endif
+
 int vio_errno(Vio *vio [[maybe_unused]]) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
