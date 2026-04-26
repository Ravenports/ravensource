--- src/sha1.c.orig	2026-02-04 13:26:07 UTC
+++ src/sha1.c
@@ -194,6 +194,7 @@ static void bin2str(char *to, const unsi
 #include "errors.h"
 
 #include <stdint.h>
+#include <string.h>
 
 #include <Rinternals.h>
 
