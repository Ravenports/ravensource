--- spa/plugins/support/cpu.c.orig	2025-09-11 08:12:34 UTC
+++ spa/plugins/support/cpu.c
@@ -12,7 +12,7 @@
 #include <sched.h>
 #include <fcntl.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -92,7 +92,7 @@ impl_cpu_force_flags(void *object, uint3
 	return 0;
 }
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 static uint32_t get_count(struct impl *this)
 {
 	cpu_set_t cpuset;
