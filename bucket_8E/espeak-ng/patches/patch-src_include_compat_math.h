--- src/include/compat/math.h.orig	2024-12-12 13:28:01 UTC
+++ src/include/compat/math.h
@@ -19,6 +19,8 @@
 #ifndef MATH_H_COMPAT_SHIM
 #define MATH_H_COMPAT_SHIM
 
+#define _NETBSD_SOURCE
+
 #ifdef _MSC_VER
 #define _USE_MATH_DEFINES // For M_PI, etc.
 #if _MSC_VER >= 1900 // Visual C++ 14 (Visual Studio 2015) and above...
