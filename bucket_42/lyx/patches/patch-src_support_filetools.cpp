--- src/support/filetools.cpp.orig	2025-01-09 19:37:38 UTC
+++ src/support/filetools.cpp
@@ -64,6 +64,8 @@
 #include <sstream>
 #include <vector>
 
+#include <sys/wait.h>
+
 #include <QCryptographicHash>
 
 #if defined (_WIN32)
