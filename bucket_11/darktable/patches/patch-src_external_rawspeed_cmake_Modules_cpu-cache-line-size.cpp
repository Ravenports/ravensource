--- src/external/rawspeed/cmake/Modules/cpu-cache-line-size.cpp.orig	2025-07-31 08:31:51 UTC
+++ src/external/rawspeed/cmake/Modules/cpu-cache-line-size.cpp
@@ -11,7 +11,7 @@
 #include <elf.h>
 #endif
 
-#if defined(_POSIX_C_SOURCE) && defined(_SC_LEVEL1_DCACHE_LINESIZE)
+#if (defined(_POSIX_C_SOURCE) || defined(__DragonFly__)) && defined(_SC_LEVEL1_DCACHE_LINESIZE)
 static std::optional<int64_t> get_cachelinesize_from_sysconf() {
   long val = ::sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
   if (val == -1) // On error, -1 is returned.
@@ -39,7 +39,7 @@ static std::optional<int64_t> get_cachel
 }
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||     \
+#if (defined(__FreeBSD__) && !defined(__MidnightBSD__)) || defined(__NetBSD__) || defined(__OpenBSD__) ||     \
     defined(__DragonFly__) || defined(__APPLE__)
 #include <cstddef>
 #include <sys/sysctl.h>
