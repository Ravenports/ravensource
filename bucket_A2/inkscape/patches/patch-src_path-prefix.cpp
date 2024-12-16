--- src/path-prefix.cpp.orig	2024-04-22 21:00:39 UTC
+++ src/path-prefix.cpp
@@ -25,7 +25,7 @@
 #include <sys/sysctl.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -227,7 +227,7 @@ char const *get_program_name()
         } else {
             g_warning("get_program_name() - sysctl failed");
         }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
        int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
        char buf[MAXPATHLEN];
        size_t cb = sizeof(buf);
