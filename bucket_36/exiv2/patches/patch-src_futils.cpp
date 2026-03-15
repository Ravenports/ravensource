--- src/futils.cpp.orig	2026-03-15 21:35:48.575499000 +0100
+++ src/futils.cpp	2026-03-15 21:36:46.608386000 +0100
@@ -35,8 +35,10 @@
 // clang-format on
 #endif
 
+#ifndef __NetBSD__
 #if __has_include(<libproc.h>)
 #include <libproc.h>
+#endif
 #endif
 
 #if __has_include(<unistd.h>)
