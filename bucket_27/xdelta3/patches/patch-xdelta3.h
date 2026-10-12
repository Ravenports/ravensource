--- xdelta3.h.orig	2026-10-08 05:38:25 UTC
+++ xdelta3.h
@@ -22,15 +22,19 @@
 #ifndef _XDELTA3_H_
 #define _XDELTA3_H_
 
+#ifdef __linux__
 #ifndef _POSIX_SOURCE
 #define _POSIX_SOURCE 200112L
 #endif
+#endif
 #ifndef _ISOC99_SOURCE
 #define _ISOC99_SOURCE
 #endif
+#ifdef __linux__
 #ifndef _C99_SOURCE
 #define _C99_SOURCE
 #endif
+#endif
 
 #if HAVE_CONFIG_H
 #include "config.h"
