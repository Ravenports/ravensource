--- src/corelib/io/qfilesystemengine_unix.cpp.orig	2025-03-27 14:17:21 UTC
+++ src/corelib/io/qfilesystemengine_unix.cpp
@@ -38,7 +38,9 @@
 
 #if __has_include(<sys/disk.h>)
 // BSDs (including Apple Darwin)
+# if !defined(__DragonFly__)
 # include <sys/disk.h>
+# endif
 #endif
 
 #if defined(Q_OS_DARWIN)
