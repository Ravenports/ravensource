--- examples/loadables/finfo.c.orig	2020-06-29 14:56:32 UTC
+++ examples/loadables/finfo.c
@@ -28,7 +28,7 @@
 #endif
 
 #include <sys/types.h>
-#ifdef MAJOR_IN_MKDEV
+#if defined MAJOR_IN_MKDEV || defined __sun__
 #  include <sys/mkdev.h>
 #endif
 #ifdef MAJOR_IN_SYSMACROS
