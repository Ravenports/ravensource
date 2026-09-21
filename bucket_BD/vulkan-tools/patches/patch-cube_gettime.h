--- cube/gettime.h.orig	2026-09-04 03:25:51 UTC
+++ cube/gettime.h
@@ -26,7 +26,7 @@
 
 #include <windows.h>
 
-#elif defined(__unix__) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__ANDROID__) || defined(__EPOC32__) || defined(__QNX__) || defined(__APPLE__)
+#elif defined(__unix__) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__ANDROID__) || defined(__EPOC32__) || defined(__QNX__) || defined(__APPLE__) || defined(__DragonFly__)
 
 #include <time.h>
 
