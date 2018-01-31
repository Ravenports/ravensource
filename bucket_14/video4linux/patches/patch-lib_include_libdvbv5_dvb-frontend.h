--- lib/include/libdvbv5/dvb-frontend.h.orig	2014-04-23 06:40:08 UTC
+++ lib/include/libdvbv5/dvb-frontend.h
@@ -27,6 +27,9 @@
 #define _DVBFRONTEND_H_
 
 #include <linux/types.h>
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 
 typedef enum fe_type {
 	FE_QPSK,
@@ -553,7 +556,13 @@ struct dtv_properties {
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
