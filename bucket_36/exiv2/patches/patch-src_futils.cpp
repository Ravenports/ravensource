--- src/futils.cpp.orig	2025-08-31 08:31:02 UTC
+++ src/futils.cpp
@@ -33,9 +33,11 @@ namespace fs = std::experimental::filesy
 // clang-format on
 #endif
 
+#ifndef __NetBSD__
 #if __has_include(<libproc.h>)
 #include <libproc.h>
 #endif
+#endif
 
 #if __has_include(<unistd.h>)
 #include <unistd.h>  // for stat()
