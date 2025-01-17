--- network.h.orig	2025-01-16 17:27:12 UTC
+++ network.h
@@ -43,7 +43,7 @@
 #endif
 
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #include <netinet/in.h>
 #endif
 
