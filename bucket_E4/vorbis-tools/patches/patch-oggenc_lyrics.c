--- oggenc/lyrics.c.orig	2020-12-18 14:49:34 UTC
+++ oggenc/lyrics.c
@@ -16,7 +16,7 @@
 #endif
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 
