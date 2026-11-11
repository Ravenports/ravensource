--- src/corelib/io/qfilesystemengine_unix.cpp.orig	2026-06-04 16:29:11 UTC
+++ src/corelib/io/qfilesystemengine_unix.cpp
@@ -38,7 +38,9 @@
 
 #if __has_include(<sys/disk.h>)
 // BSDs (including Apple Darwin)
+# if !defined(__DragonFly__)
 # include <sys/disk.h>
+# endif
 #endif
 
 #if defined(Q_OS_DARWIN)
