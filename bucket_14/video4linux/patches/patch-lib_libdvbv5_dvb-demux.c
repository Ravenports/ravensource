--- lib/libdvbv5/dvb-demux.c.orig	2014-09-07 16:37:14 UTC
+++ lib/libdvbv5/dvb-demux.c
@@ -37,6 +37,9 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdlib.h> /* free */
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 
 #include <libdvbv5/dvb-demux.h>
 
