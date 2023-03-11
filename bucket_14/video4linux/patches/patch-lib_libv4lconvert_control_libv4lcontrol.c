--- lib/libv4lconvert/control/libv4lcontrol.c.orig	2023-02-24 16:49:19 UTC
+++ lib/libv4lconvert/control/libv4lcontrol.c
@@ -20,7 +20,7 @@
  */
 
 #include <sys/types.h>
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
 #endif
 #include <sys/mman.h>
