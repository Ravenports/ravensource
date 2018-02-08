--- include/linux/dvb/frontend.h.orig	2014-09-07 17:18:12 UTC
+++ include/linux/dvb/frontend.h
@@ -26,6 +26,9 @@
 #ifndef _DVBFRONTEND_H_
 #define _DVBFRONTEND_H_
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 #include <linux/types.h>
 
 typedef enum fe_type {
@@ -549,7 +552,13 @@ struct dtv_properties {
 };
 
 #define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
-#define FE_GET_PROPERTY		   _IOR('o', 83, struct dtv_properties)
+/* 
+ * This is broken on linux as well but they workaround it in the driver.
+ * Since this is impossible to do on FreeBSD fix the header instead.
+ * Detailed and discussion :
+ * http://lists.freebsd.org/pipermail/freebsd-multimedia/2010-April/010958.html
+ */
+#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)
 
 
 /**
