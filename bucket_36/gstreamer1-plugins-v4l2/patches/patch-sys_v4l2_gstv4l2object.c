--- sys/v4l2/gstv4l2object.c.orig	2026-01-27 17:02:33 UTC
+++ sys/v4l2/gstv4l2object.c
@@ -5385,7 +5385,9 @@ gst_v4l2_object_probe_caps (GstV4l2Objec
     if (v4l2object->ioctl (v4l2object->video_fd, VIDIOC_CROPCAP, &cropcap) < 0) {
 
       switch (errno) {
+#ifdef ENODATA
         case ENODATA:
+#endif
         case ENOTTY:
           GST_INFO_OBJECT (v4l2object->dbg_obj,
               "Driver does not support VIDIOC_CROPCAP (%s), assuming pixel aspect ratio 1/1",
