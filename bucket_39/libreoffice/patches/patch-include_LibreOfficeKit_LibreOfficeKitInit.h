--- include/LibreOfficeKit/LibreOfficeKitInit.h.orig	2020-08-27 19:21:14 UTC
+++ include/LibreOfficeKit/LibreOfficeKitInit.h
@@ -25,7 +25,7 @@ extern "C"
 
 #if defined(__linux__) || defined (__FreeBSD_kernel__) || defined(_AIX) ||\
     defined(_WIN32) || defined(__APPLE__) || defined (__NetBSD__) ||\
-    defined (__sun) || defined(__OpenBSD__)
+    defined (__sun) || defined(__OpenBSD__) || defined (__FreeBSD__) || defined (__DragonFly__)
 
 #include <stdio.h>
 #include <stdlib.h>
