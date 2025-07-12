--- examples/loadables/finfo.c.orig	2023-10-30 19:01:06 UTC
+++ examples/loadables/finfo.c
@@ -28,7 +28,7 @@
 #endif
 
 #include <sys/types.h>
-#ifdef MAJOR_IN_MKDEV
+#if defined MAJOR_IN_MKDEV || defined __sun__
 #  include <sys/mkdev.h>
 #endif
 #ifdef MAJOR_IN_SYSMACROS
