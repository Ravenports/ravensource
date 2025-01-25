--- src/external/rawspeed/cmake/Modules/cpu-page-size.cpp.orig	2024-12-13 20:15:16 UTC
+++ src/external/rawspeed/cmake/Modules/cpu-page-size.cpp
@@ -4,7 +4,7 @@
 #include <unistd.h>
 #endif
 
-#if (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 1) || defined(__APPLE__)
+#if (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 1) || defined(__APPLE__) || defined(__DragonFly__) || defined(__MidnightBSD__)
 
 int main() {
   long val = ::sysconf(_SC_PAGESIZE);
