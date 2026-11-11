--- src/gui/platform/unix/qxdgdesktopportalfiletransfer.cpp.orig	2026-06-04 16:29:11 UTC
+++ src/gui/platform/unix/qxdgdesktopportalfiletransfer.cpp
@@ -17,6 +17,10 @@
 #include <unistd.h>
 #include <fcntl.h>
 
+#ifndef O_PATH
+#  define O_PATH O_RDONLY
+#endif
+
 QT_BEGIN_NAMESPACE
 
 using namespace Qt::StringLiterals;
