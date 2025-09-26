--- network.h.orig	2025-09-25 16:14:00 UTC
+++ network.h
@@ -43,7 +43,7 @@
 #endif
 
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #include <netinet/in.h>
 #endif
 
