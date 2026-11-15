--- src/file/kinotify.cpp.orig	2026-11-07 15:23:20 UTC
+++ src/file/kinotify.cpp
@@ -28,6 +28,10 @@
 #include <cerrno>
 #include <dirent.h>
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
+
 namespace
 {
 QByteArray normalizeTrailingSlash(QByteArray&& path)
