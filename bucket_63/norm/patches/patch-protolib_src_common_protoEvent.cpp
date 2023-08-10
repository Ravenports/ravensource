--- protolib/src/common/protoEvent.cpp.orig	2023-08-10 11:36:42 UTC
+++ protolib/src/common/protoEvent.cpp
@@ -8,7 +8,7 @@
 #include <string.h>   // for memset()
 #include <unistd.h>
 #include <fcntl.h>
-#ifdef LINUX
+#if defined LINUX || defined(__FreeBSD__)
 #include <sys/eventfd.h>
 #endif // LINUX
 #endif  // if/else WIN32/UNIX
