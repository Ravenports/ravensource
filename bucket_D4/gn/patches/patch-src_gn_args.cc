--- src/gn/args.cc.orig	2020-02-20 17:50:20 UTC
+++ src/gn/args.cc
@@ -308,6 +308,8 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_DRAGONFLY)
+  os = "freebsd";
 #elif defined(OS_FREEBSD)
   os = "freebsd";
 #elif defined(OS_AIX)
