--- src/whereami.c.orig	2026-07-11 11:11:28 UTC
+++ src/whereami.c
@@ -24,6 +24,7 @@ extern "C" {
 
 #if !defined(WAI_MALLOC) || !defined(WAI_FREE) || !defined(WAI_REALLOC)
 #include <stdlib.h>
+#include <limits.h>
 #include "avrdude.h"
 #include "libavrdude.h"
 
