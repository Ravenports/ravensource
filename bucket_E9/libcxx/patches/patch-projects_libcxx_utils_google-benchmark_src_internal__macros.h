--- projects/libcxx/utils/google-benchmark/src/internal_macros.h.orig	2021-09-24 16:18:10 UTC
+++ projects/libcxx/utils/google-benchmark/src/internal_macros.h
@@ -56,7 +56,7 @@
       #define BENCHMARK_OS_IOS 1
     #endif
   #endif
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   #define BENCHMARK_OS_FREEBSD 1
 #elif defined(__NetBSD__)
   #define BENCHMARK_OS_NETBSD 1
