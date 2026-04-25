--- sal/osl/unx/process.cxx.orig	2026-04-09 16:07:27 UTC
+++ sal/osl/unx/process.cxx
@@ -43,6 +43,7 @@
 
 #if defined(FREEBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #include <machine/param.h>
+#include <signal.h>  // for kill()
 #endif
 
 #if defined(IOS) || defined(FREEBSD)
