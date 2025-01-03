--- libs/process/src/ext/exe.cpp.orig	2024-12-05 00:53:35 UTC
+++ libs/process/src/ext/exe.cpp
@@ -39,7 +39,7 @@
 #if (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
-#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
 #endif
 #endif
@@ -138,7 +138,7 @@ filesystem::path exe(boost::process::v2:
             filesystem::path("/proc") / std::to_string(pid) / "exe", ec
             );
 #elif defined(__sun)
-    return fileystem::canonical(
+    return filesystem::canonical(
             filesystem::path("/proc") / std::to_string(pid) / "path/a.out", ec
             );
 #endif
