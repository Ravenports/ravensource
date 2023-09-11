--- src/gn/args.cc.orig	2022-11-10 16:29:39 UTC
+++ src/gn/args.cc
@@ -310,8 +310,12 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_DRAGONFLY)
+  os = "freebsd";
 #elif defined(OS_FREEBSD)
   os = "freebsd";
+#elif defined(OS_NETBSD)
+  os = "netbsd";
 #elif defined(OS_AIX)
   os = "aix";
 #elif defined(OS_OPENBSD)
