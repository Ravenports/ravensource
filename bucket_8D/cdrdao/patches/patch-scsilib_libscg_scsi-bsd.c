--- scsilib/libscg/scsi-bsd.c.orig	2018-05-16 10:46:58 UTC
+++ scsilib/libscg/scsi-bsd.c
@@ -548,10 +548,17 @@ scgo_send(scgp)
 #define	scsi_sense CAM_scsi_sense
 #define	scsi_inquiry CAM_scsi_inquiry
 #include <sys/param.h>
+#ifdef __DragonFly__
+#include <bus/cam/cam.h>
+#include <bus/cam/cam_ccb.h>
+#include <bus/cam/scsi/scsi_message.h>
+#include <bus/cam/scsi/scsi_pass.h>
+#else
 #include <cam/cam.h>
 #include <cam/cam_ccb.h>
 #include <cam/scsi/scsi_message.h>
 #include <cam/scsi/scsi_pass.h>
+#endif
 #include <camlib.h>
 
 /*
