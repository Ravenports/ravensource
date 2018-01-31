--- lib/include/libv4l2.h.orig	2013-06-28 20:10:56 UTC
+++ lib/include/libv4l2.h
@@ -20,7 +20,9 @@
 #define __LIBV4L2_H
 
 #include <stdio.h>
+#ifndef __sun__
 #include <unistd.h>
+#endif
 #include <stdint.h>
 
 #ifdef __cplusplus
