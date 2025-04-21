--- scribus/third_party/pgf/PGFplatform.h.orig	2025-04-21 19:50:52 UTC
+++ scribus/third_party/pgf/PGFplatform.h
@@ -336,7 +336,7 @@ inline OSError SetFPos(HANDLE hFile, int
 //-------------------------------------------------------------------------------
 // *BSD and Haiku
 //-------------------------------------------------------------------------------
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__DragonFly__)
 #ifndef __POSIX__ 
 #define __POSIX__ 
 #endif 
