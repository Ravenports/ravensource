--- src/futils.cpp.orig	2026-08-30 19:33:50 UTC
+++ src/futils.cpp
@@ -35,9 +35,11 @@ namespace fs = std::experimental::filesy
 // clang-format on
 #endif
 
+#ifndef __NetBSD__
 #if __has_include(<libproc.h>)
 #include <libproc.h>
 #endif
+#endif
 
 #if __has_include(<unistd.h>)
 #include <unistd.h>  // for stat()
