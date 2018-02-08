--- linux/dvb/frontend.h.orig	2014-12-01 09:58:18 UTC
+++ linux/dvb/frontend.h
@@ -26,6 +26,9 @@
 #ifndef _DVBFRONTEND_H_
 #define _DVBFRONTEND_H_
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 #include <linux/types.h>
 
 typedef enum fe_type {
