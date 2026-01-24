--- sal/osl/unx/process.cxx.orig	2026-01-14 23:16:14 UTC
+++ sal/osl/unx/process.cxx
@@ -43,6 +43,7 @@
 
 #if defined(FREEBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #include <machine/param.h>
+#include <signal.h>  // for kill()
 #endif
 
 #if defined(IOS) || defined(FREEBSD)
