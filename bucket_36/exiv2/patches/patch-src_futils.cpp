--- src/futils.cpp.orig	2024-02-13 17:32:04 UTC
+++ src/futils.cpp
@@ -30,9 +30,11 @@ namespace fs = std::experimental::filesy
 // clang-format on
 #endif
 
+#ifndef __NetBSD__
 #if __has_include(<libproc.h>)
 #include <libproc.h>
 #endif
+#endif
 
 #if __has_include(<unistd.h>)
 #include <unistd.h>  // for stat()
