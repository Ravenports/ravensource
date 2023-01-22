--- videodev2.h.orig	2023-01-22 21:02:06 UTC
+++ videodev2.h
@@ -66,6 +66,10 @@
 #include <linux/v4l2-common.h>
 #include <linux/v4l2-controls.h>
 
+#if defined(__NetBSD__)
+#define	_IOWINT(g,n)	_IOC(IOC_VOID, (g), (n), sizeof(int))
+#endif
+
 /*
  * Common stuff for both V4L1 and V4L2
  * Moved from videodev.h
