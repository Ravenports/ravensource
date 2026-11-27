* define ppoll on older NetBSD that only has pollts

--- vio/viosocket.cc.orig	2026-11-06 09:09:05 UTC
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
