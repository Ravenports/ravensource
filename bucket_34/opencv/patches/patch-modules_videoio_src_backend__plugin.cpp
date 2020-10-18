--- modules/videoio/src/backend_plugin.cpp.orig	2020-10-11 21:26:07 UTC
+++ modules/videoio/src/backend_plugin.cpp
@@ -21,7 +21,7 @@ using namespace std;
 
 #if defined(_WIN32)
 #include <windows.h>
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__DragonFly__)
 #include <dlfcn.h>
 #endif
 
@@ -77,7 +77,7 @@ void* getSymbol_(LibHandle_t h, const ch
 {
 #if defined(_WIN32)
     return (void*)GetProcAddress(h, symbolName);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__DragonFly__)
     return dlsym(h, symbolName);
 #endif
 }
@@ -91,7 +91,7 @@ LibHandle_t libraryLoad_(const FileSyste
 # else
     return LoadLibraryW(filename.c_str());
 #endif
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__DragonFly__)
     return dlopen(filename.c_str(), RTLD_LAZY);
 #endif
 }
@@ -101,7 +101,7 @@ void libraryRelease_(LibHandle_t h)
 {
 #if defined(_WIN32)
     FreeLibrary(h);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__DragonFly__)
     dlclose(h);
 #endif
 }
