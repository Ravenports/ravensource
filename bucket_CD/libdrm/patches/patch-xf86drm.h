--- xf86drm.h.orig	2019-01-22 16:32:41 UTC
+++ xf86drm.h
@@ -59,6 +59,9 @@ extern "C" {
 #else /* One of the *BSDs */
 
 #include <sys/ioccom.h>
+#ifdef __sun__
+#define _IOC(inout,group,num,len)	(inout | ((len & IOCPARM_MASK) << 16) | ((group) << 8) | (num))
+#endif
 #define DRM_IOCTL_NR(n)         ((n) & 0xff)
 #define DRM_IOC_VOID            IOC_VOID
 #define DRM_IOC_READ            IOC_OUT
@@ -78,17 +81,27 @@ extern "C" {
 
 #ifdef __OpenBSD__
 #define DRM_DIR_NAME  "/dev"
-#define DRM_DEV_NAME  "%s/drm%d"
-#define DRM_CONTROL_DEV_NAME  "%s/drmC%d"
-#define DRM_RENDER_DEV_NAME  "%s/drmR%d"
+#define DRM_PRIMARY_MINOR_NAME  "drm"
+#define DRM_CONTROL_MINOR_NAME  "drmC"
+#define DRM_RENDER_MINOR_NAME   "drmR"
 #else
 #define DRM_DIR_NAME  "/dev/dri"
-#define DRM_DEV_NAME  "%s/card%d"
-#define DRM_CONTROL_DEV_NAME  "%s/controlD%d"
-#define DRM_RENDER_DEV_NAME  "%s/renderD%d"
-#define DRM_PROC_NAME "/proc/dri/" /* For backward Linux compatibility */
+#define DRM_PRIMARY_MINOR_NAME  "card"
+#define DRM_CONTROL_MINOR_NAME  "controlD"
+#define DRM_RENDER_MINOR_NAME   "renderD"
 #endif
 
+#define DRM_DEV_NAME  "%s/" DRM_PRIMARY_MINOR_NAME "%d"
+#define DRM_CONTROL_DEV_NAME  "%s/" DRM_CONTROL_MINOR_NAME "%d"
+#define DRM_RENDER_DEV_NAME  "%s/" DRM_RENDER_MINOR_NAME "%d"
+
+#define DRM_NODE_NAME_MAX                   \
+    (sizeof(DRM_DIR_NAME) +                 \
+     MAX3(sizeof(DRM_PRIMARY_MINOR_NAME),   \
+         sizeof(DRM_CONTROL_MINOR_NAME),    \
+         sizeof(DRM_RENDER_MINOR_NAME))     \
+    + 3) /* length of the node number */
+
 #define DRM_ERR_NO_DEVICE  (-1001)
 #define DRM_ERR_NO_ACCESS  (-1002)
 #define DRM_ERR_NOT_ROOT   (-1003)
