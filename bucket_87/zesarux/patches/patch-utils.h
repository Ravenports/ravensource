--- utils.h.orig	2024-06-06 15:45:53 UTC
+++ utils.h
@@ -22,7 +22,7 @@
 #ifndef UTILS_H
 #define UTILS_H
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #include <limits.h>
 #endif
 
