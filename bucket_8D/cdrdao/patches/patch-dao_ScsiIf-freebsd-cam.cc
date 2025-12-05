--- dao/ScsiIf-freebsd-cam.cc.orig	2025-12-05 11:17:35 UTC
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
@@ -220,6 +224,12 @@ int ScsiIf::inquiry()
 	for (i = 3; i >= 0 && revision_[i] == ' '; i--)
 		revision_[i] = 0;
 
+	if (vendor_[0] == 0)
+		strncpy(vendor_, "UNKNOWN", 8);
+
+	if (product_[0] == 0)
+		strncpy(product_, "UNKNOWN", 8);
+
 	return 0;
 }
 
