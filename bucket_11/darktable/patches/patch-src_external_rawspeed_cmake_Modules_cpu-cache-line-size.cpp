--- src/external/rawspeed/cmake/Modules/cpu-cache-line-size.cpp.orig	2024-12-31 00:33:15 UTC
+++ src/external/rawspeed/cmake/Modules/cpu-cache-line-size.cpp
@@ -11,7 +11,7 @@
 #include <elf.h>
 #endif
 
-#if defined(_POSIX_C_SOURCE) && defined(_SC_LEVEL1_DCACHE_LINESIZE)
+#if (defined(_POSIX_C_SOURCE) || defined(__DragonFly__)) && defined(_SC_LEVEL1_DCACHE_LINESIZE)
 static std::optional<int64_t> get_cachelinesize_from_sysconf() {
   long val = ::sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
   if (val == -1) // On error, -1 is returned.
