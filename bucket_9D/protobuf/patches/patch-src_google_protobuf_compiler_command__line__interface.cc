--- src/google/protobuf/compiler/command_line_interface.cc.orig	2024-03-27 17:31:42 UTC
+++ src/google/protobuf/compiler/command_line_interface.cc
@@ -57,7 +57,7 @@
 
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -208,7 +208,7 @@ bool GetProtocAbsolutePath(std::string*
     realpath(dirtybuffer, buffer);
     len = strlen(buffer);
   }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   char buffer[PATH_MAX];
   size_t len = PATH_MAX;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
