--- lib/Support/Unix/Program.inc.orig	2016-04-05 20:45:04 UTC
+++ lib/Support/Unix/Program.inc
@@ -40,9 +40,6 @@
 #include <unistd.h>
 #endif
 #ifdef HAVE_POSIX_SPAWN
-#ifdef __sun__
-#define  _RESTRICT_KYWD
-#endif
 #include <spawn.h>
 
 #if defined(__APPLE__)
