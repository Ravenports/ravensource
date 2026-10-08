--- src/whereami.c.orig	2026-09-11 07:19:44 UTC
+++ src/whereami.c
@@ -25,6 +25,7 @@ extern "C" {
 
 #if !defined(WAI_MALLOC) || !defined(WAI_FREE) || !defined(WAI_REALLOC)
 #include <stdlib.h>
+#include <limits.h>
 #include "avrdude.h"
 #include "libavrdude.h"
 
