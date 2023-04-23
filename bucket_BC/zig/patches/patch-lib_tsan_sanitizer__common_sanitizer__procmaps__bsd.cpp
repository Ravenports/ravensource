--- lib/tsan/sanitizer_common/sanitizer_procmaps_bsd.cpp.orig	2023-01-17 23:40:56 UTC
+++ lib/tsan/sanitizer_common/sanitizer_procmaps_bsd.cpp
@@ -29,13 +29,6 @@
 
 #include <limits.h>
 
-// Fix 'kinfo_vmentry' definition on FreeBSD prior v9.2 in 32-bit mode.
-#if SANITIZER_FREEBSD && (SANITIZER_WORDSIZE == 32)
-#include <osreldate.h>
-#if __FreeBSD_version <= 902001 // v9.2
-#define kinfo_vmentry xkinfo_vmentry
-#endif
-#endif
 
 namespace __sanitizer {
 
