--- Source/ZLib/gzguts.h.orig	2017-01-01 20:37:10 UTC
+++ Source/ZLib/gzguts.h
@@ -18,6 +18,7 @@
 #  define ZLIB_INTERNAL
 #endif
 
+#include <unistd.h>
 #include <stdio.h>
 #include "zlib.h"
 #ifdef STDC
