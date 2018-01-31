--- lib/libv4lconvert/control/libv4lcontrol.c.orig	2015-05-06 19:24:59 UTC
+++ lib/libv4lconvert/control/libv4lcontrol.c
@@ -37,6 +37,32 @@
 #include "../libv4lsyscall-priv.h"
 #include <linux/videodev2.h>
 
+#ifdef __sun__
+
+
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+
+static char *strndup (const char *str, size_t max)
+{
+    size_t len = strnlen (str, max);
+    char *res = malloc (len + 1);
+    if (res)
+    {
+        memcpy (res, str, len);
+        res[len] = '\0';
+    }
+    return res;
+}
+#endif
+
 #define ARRAY_SIZE(x) ((int)sizeof(x) / (int)sizeof((x)[0]))
 
 /* List of cams which need special flags */
@@ -361,6 +387,19 @@ static int v4lcontrol_get_usb_info(struc
 		unsigned short *vendor_id, unsigned short *product_id,
 		int *speed)
 {
+#ifdef __FreeBSD__
+#define WEBCAMD_IOCTL_GET_USB_VENDOR_ID _IOR('q', 250, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_PRODUCT_ID _IOR('q', 251, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_SPEED _IOR('q', 252, unsigned int)
+	if (ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_VENDOR_ID, vendor_id) == 0 &&
+	    ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_PRODUCT_ID, product_id) == 0 &&
+	    ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_SPEED, speed) == 0)
+		return (1);
+	return (0);
+#elif defined __sun__
+	/* implement later? */
+	return (0);
+#else
 	FILE *f;
 	int i, minor;
 	struct stat st;
@@ -457,6 +496,7 @@ static int v4lcontrol_get_usb_info(struc
 		return 0; /* Should never happen */
 
 	return 1;
+#endif
 }
 
 /*
@@ -570,6 +610,10 @@ static void v4lcontrol_get_flags_from_db
 struct v4lcontrol_data *v4lcontrol_create(int fd, void *dev_ops_priv,
 	const struct libv4l_dev_ops *dev_ops, int always_needs_conversion)
 {
+#ifdef __sun__
+	printf("libv4lcontrol: not implemented on sunos yet\n");
+	return NULL;
+#else
 	int shm_fd;
 	int i, rc, got_usb_info, speed, init = 0;
 	char *s, shm_name[256], pwd_buf[1024];
@@ -771,6 +815,7 @@ struct v4lcontrol_data *v4lcontrol_creat
 error:
 	free(data);
 	return NULL;
+#endif
 }
 
 void v4lcontrol_destroy(struct v4lcontrol_data *data)
