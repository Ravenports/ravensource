--- xdelta3.h.orig	2026-06-21 04:37:32 UTC
+++ xdelta3.h
@@ -22,9 +22,11 @@
 #ifndef _XDELTA3_H_
 #define _XDELTA3_H_
 
+#ifdef __linux__
 #define _POSIX_SOURCE 200112L
-#define _ISOC99_SOURCE
 #define _C99_SOURCE
+#endif
+#define _ISOC99_SOURCE
 
 #if HAVE_CONFIG_H
 #include "config.h"
