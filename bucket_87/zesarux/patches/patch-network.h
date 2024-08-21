--- network.h.orig	2024-06-06 15:45:53 UTC
+++ network.h
@@ -43,7 +43,7 @@
 #endif
 
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <netinet/in.h>
 #endif
 
