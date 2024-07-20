--- src/google/protobuf/compiler/command_line_interface.cc.orig	2024-06-25 17:53:13 UTC
+++ src/google/protobuf/compiler/command_line_interface.cc
@@ -62,7 +62,7 @@
 
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -219,7 +219,7 @@ bool GetProtocAbsolutePath(std::string*
     realpath(dirtybuffer, buffer);
     len = strlen(buffer);
   }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   char buffer[PATH_MAX];
   size_t len = PATH_MAX;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
