--- src/support/filetools.cpp.orig	2026-09-07 18:54:34 UTC
+++ src/support/filetools.cpp
@@ -61,6 +61,8 @@
 #include <sstream>
 #include <vector>
 
+#include <sys/wait.h>
+
 #include <QCryptographicHash>
 
 #if defined (_WIN32)
