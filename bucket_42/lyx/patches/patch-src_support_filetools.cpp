--- src/support/filetools.cpp.orig	2024-05-25 21:51:22 UTC
+++ src/support/filetools.cpp
@@ -64,6 +64,8 @@
 #include <sstream>
 #include <vector>
 
+#include <sys/wait.h>
+
 #include <QCryptographicHash>
 
 #if defined (_WIN32)
