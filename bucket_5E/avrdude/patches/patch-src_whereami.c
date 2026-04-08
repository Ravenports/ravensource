--- src/whereami.c.orig	2025-06-23 09:03:44 UTC
+++ src/whereami.c
@@ -15,6 +15,7 @@ extern "C" {
 
 #if !defined(WAI_MALLOC) || !defined(WAI_FREE) || !defined(WAI_REALLOC)
 #include <stdlib.h>
+#include <limits.h>
 
 #ifndef PATH_MAX
 #define PATH_MAX _MAX_PATH
