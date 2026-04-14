--- sys/v4l2/gstv4l2object.c.orig	2026-02-26 01:44:06 UTC
+++ sys/v4l2/gstv4l2object.c
@@ -654,7 +654,11 @@ gst_v4l2_object_new (GstElement * elemen
     v4l2object->fd_open = NULL;
     v4l2object->close = close;
     v4l2object->dup = dup;
+#ifdef __sun
+    v4l2object->ioctl = (gint (*) (gint, ioctl_req_t, ...)) ioctl;
+#else
     v4l2object->ioctl = ioctl;
+#endif
     v4l2object->read = read;
     v4l2object->mmap = mmap;
     v4l2object->munmap = munmap;
@@ -5393,7 +5397,9 @@ gst_v4l2_object_probe_caps (GstV4l2Objec
     if (v4l2object->ioctl (v4l2object->video_fd, VIDIOC_CROPCAP, &cropcap) < 0) {
 
       switch (errno) {
+#ifdef ENODATA
         case ENODATA:
+#endif
         case ENOTTY:
           GST_INFO_OBJECT (v4l2object->dbg_obj,
               "Driver does not support VIDIOC_CROPCAP (%s), assuming pixel aspect ratio 1/1",
