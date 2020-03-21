--- compat/cpuset.h.orig	2020-03-17 10:00:17 UTC
+++ compat/cpuset.h
@@ -41,7 +41,7 @@ typedef cpu_set_t cpuset_t;
 #ifdef __linux__
 typedef int cpuid_t;
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 typedef size_t cpuid_t;
 #endif
 #endif
