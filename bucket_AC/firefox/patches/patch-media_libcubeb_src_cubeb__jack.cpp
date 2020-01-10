--- media/libcubeb/src/cubeb_jack.cpp.orig	2020-01-03 18:58:02 UTC
+++ media/libcubeb/src/cubeb_jack.cpp
@@ -8,7 +8,7 @@
  */
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
-#ifndef __FreeBSD__
+#if !(defined __FreeBSD__ || defined __DragonFly__)
 #define _POSIX_SOURCE
 #endif
 #include <dlfcn.h>
