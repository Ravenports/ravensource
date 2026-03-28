--- src/support/filetools.cpp.orig	2026-02-08 18:44:53 UTC
+++ src/support/filetools.cpp
@@ -61,6 +61,8 @@
 #include <sstream>
 #include <vector>
 
+#include <sys/wait.h>
+
 #include <QCryptographicHash>
 
 #if defined (_WIN32)
