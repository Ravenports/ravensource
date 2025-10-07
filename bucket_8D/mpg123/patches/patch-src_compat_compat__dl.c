--- src/compat/compat_dl.c.orig	2025-08-05 18:24:40 UTC
+++ src/compat/compat_dl.c
@@ -10,11 +10,10 @@
 */
 
 #include "config.h"
-/* This source file does need _POSIX_SOURCE to get some sigaction. */
-#define _POSIX_SOURCE
 /* Fix pedantic error about w2upath being unused */
 #define HIDE_w2upath
 #include "compat.h"
+#include <dlfcn.h>
 
 #ifdef _MSC_VER
 #include <io.h>
