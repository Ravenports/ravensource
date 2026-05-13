--- sal/osl/unx/process.cxx.orig	2026-04-24 19:21:51 UTC
+++ sal/osl/unx/process.cxx
@@ -43,6 +43,7 @@
 
 #if defined(FREEBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #include <machine/param.h>
+#include <signal.h>  // for kill()
 #endif
 
 #if defined(IOS) || defined(FREEBSD)
