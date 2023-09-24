--- src/include/xlsxwriter/third_party/ioapi.h.orig	2023-01-06 17:19:12 UTC
+++ src/include/xlsxwriter/third_party/ioapi.h
@@ -56,7 +56,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
