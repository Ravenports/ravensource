--- src/usage.cpp.orig	2026-01-01 05:43:43 UTC
+++ src/usage.cpp
@@ -17,6 +17,9 @@
 #else
 	#include <sys/ioctl.h>
 #endif
+#if defined(__sun)
+#include <sys/termios.h>
+#endif
 
 void Usage::printVersion(bool error) const {
 	fprintf(error ? stderr : stdout, "%s %s\n", name.c_str(), get_package_version_string());
