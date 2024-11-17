--- timidity/wave_a.c.orig	2014-05-22 09:09:04 UTC
+++ timidity/wave_a.c
@@ -30,6 +30,8 @@
 #include <sys/types.h>
 #endif // for off_t
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef __W32__
 #include <io.h>
