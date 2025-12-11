--- sal/osl/unx/process.cxx.orig	2025-12-01 19:30:03 UTC
+++ sal/osl/unx/process.cxx
@@ -43,6 +43,7 @@
 
 #if defined(FREEBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #include <machine/param.h>
+#include <signal.h>  // for kill()
 #endif
 
 #ifdef IOS
