* define ppoll on older NetBSD that only has pollts

--- vio/viosocket.cc.orig	2023-06-21 07:52:10 UTC
+++ vio/viosocket.cc
@@ -71,6 +71,13 @@
 
 #include "mysql/psi/mysql_socket.h"
 
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
