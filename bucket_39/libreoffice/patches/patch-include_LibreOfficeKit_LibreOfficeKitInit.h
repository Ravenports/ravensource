--- include/LibreOfficeKit/LibreOfficeKitInit.h.orig	2021-12-21 19:06:48 UTC
+++ include/LibreOfficeKit/LibreOfficeKitInit.h
@@ -20,7 +20,7 @@
 
 #if defined(__linux__) || defined (__FreeBSD__) || defined(_AIX) ||\
     defined(_WIN32) || defined(__APPLE__) || defined (__NetBSD__) ||\
-    defined (__sun) || defined(__OpenBSD__)
+    defined (__sun) || defined(__OpenBSD__) || defined (__FreeBSD__) || defined (__DragonFly__)
 
 #include <stdio.h>
 #include <stdlib.h>
