--- sal/osl/unx/process.cxx.orig	2024-07-10 15:12:43 UTC
+++ sal/osl/unx/process.cxx
@@ -43,6 +43,7 @@
 
 #if defined(FREEBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #include <machine/param.h>
+#include <signal.h>  // for kill()
 #endif
 
 #ifdef IOS
