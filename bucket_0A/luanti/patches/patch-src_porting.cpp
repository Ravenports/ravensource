--- src/porting.cpp.orig	2026-04-14 20:04:31 UTC
+++ src/porting.cpp
@@ -14,6 +14,9 @@
 	#include <sys/types.h>
 	#include <sys/sysctl.h>
 	extern char **environ;
+#elif defined(__sun)
+	#include <sys/types.h>
+	extern char **environ;
 #elif defined(_WIN32)
 	#include <windows.h>
 	#include <wincrypt.h>
