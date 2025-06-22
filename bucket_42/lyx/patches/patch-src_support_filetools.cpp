--- src/support/filetools.cpp.orig	2025-06-05 21:39:49 UTC
+++ src/support/filetools.cpp
@@ -64,6 +64,8 @@
 #include <sstream>
 #include <vector>
 
+#include <sys/wait.h>
+
 #include <QCryptographicHash>
 
 #if defined (_WIN32)
