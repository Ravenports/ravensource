--- modules/core/include/opencv2/core/utils/plugin_loader.private.hpp.orig	2025-07-02 07:54:13 UTC
+++ modules/core/include/opencv2/core/utils/plugin_loader.private.hpp
@@ -12,7 +12,7 @@
 
 #if defined(_WIN32)
 #include <windows.h>
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -65,7 +65,7 @@ void* getSymbol_(LibHandle_t h, const ch
 {
 #if defined(_WIN32)
     return (void*)GetProcAddress(h, symbolName);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__NetBSD__)
     return dlsym(h, symbolName);
 #endif
 }
@@ -79,7 +79,7 @@ LibHandle_t libraryLoad_(const FileSyste
 # else
     return LoadLibraryW(filename.c_str());
 #endif
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__NetBSD__)
     void* handle = dlopen(filename.c_str(), RTLD_NOW);
     CV_LOG_IF_DEBUG(NULL, !handle, "dlopen() error: " << dlerror());
     return handle;
@@ -91,7 +91,7 @@ void libraryRelease_(LibHandle_t h)
 {
 #if defined(_WIN32)
     FreeLibrary(h);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__NetBSD__)
     dlclose(h);
 #endif
 }
