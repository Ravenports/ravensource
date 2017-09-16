--- common/cpu.c.orig	2017-06-26 20:45:05 UTC
+++ common/cpu.c
@@ -33,7 +33,7 @@
 #if SYS_BEOS
 #include <kernel/OS.h>
 #endif
-#if SYS_MACOSX || SYS_FREEBSD
+#if SYS_MACOSX || SYS_FREEBSD || SYS_DRAGONFLY
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -341,6 +341,13 @@ uint32_t x264_cpu_detect( void )
     return cpu;
 }
 
+#elif SYS_DRAGONFLY
+
+uint32_t x264_cpu_detect( void )
+{
+    return 0;
+}
+
 #elif SYS_LINUX
 
 uint32_t x264_cpu_detect( void )
@@ -478,7 +485,7 @@ int x264_cpu_num_processors( void )
     get_system_info( &info );
     return info.cpu_count;
 
-#elif SYS_MACOSX || SYS_FREEBSD || SYS_OPENBSD
+#elif SYS_MACOSX || SYS_FREEBSD || SYS_OPENBSD || SYS_DRAGONFLY
     int ncpu;
     size_t length = sizeof( ncpu );
 #if SYS_OPENBSD
