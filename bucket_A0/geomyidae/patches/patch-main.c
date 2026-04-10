--- main.c.orig	2025-07-30 07:47:54 UTC
+++ main.c
@@ -36,6 +36,13 @@
 #include "ind.h"
 #include "handlr.h"
 #include "arg.h"
+#if defined(__sun)
+#include "dprintf.h"
+#endif
+
+#ifndef LOG_PERROR
+#define LOG_PERROR 0
+#endif
 
 enum {
 	NOLOG	= 0,
