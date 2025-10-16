--- src/corelib/io/qfilesystemengine_unix.cpp.orig	2025-08-11 04:54:51 UTC
+++ src/corelib/io/qfilesystemengine_unix.cpp
@@ -39,7 +39,9 @@
 
 #if __has_include(<sys/disk.h>)
 // BSDs (including Apple Darwin)
+# if !defined(__DragonFly__)
 # include <sys/disk.h>
+# endif
 #endif
 
 #if defined(Q_OS_DARWIN)
