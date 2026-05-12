--- src/lib/lib.h.orig	2026-05-12 10:48:57 UTC
+++ src/lib/lib.h
@@ -1,7 +1,7 @@
 #ifndef LIB_H
 #define LIB_H
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #  define __BSD_VISIBLE 1
 #elif defined(__APPLE__)
 #  define _DARWIN_C_SOURCE 1
