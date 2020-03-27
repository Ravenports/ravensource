--- dao/ScsiIf-freebsd-cam.cc.orig	2018-05-16 10:46:39 UTC
+++ dao/ScsiIf-freebsd-cam.cc
@@ -28,7 +28,11 @@
 #include <string.h>
 
 #include <camlib.h>
+#ifdef __DragonFly__
+#include <bus/cam/scsi/scsi_message.h>
+#else
 #include <cam/scsi/scsi_message.h>
+#endif
 
 #include "ScsiIf.h"
 #include "log.h"
