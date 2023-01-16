--- videodev2.h.orig	2023-01-16 02:01:18 UTC
+++ videodev2.h
@@ -65,6 +65,10 @@
 #include <linux/v4l2-common.h>
 #include <linux/v4l2-controls.h>
 
+#if defined(__NetBSD__)
+#define	_IOWINT(g,n)	_IOC(IOC_VOID, (g), (n), sizeof(int))
+#endif
+
 /*
  * Common stuff for both V4L1 and V4L2
  * Moved from videodev.h
