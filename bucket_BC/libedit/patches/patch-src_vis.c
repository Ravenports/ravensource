--- src/vis.c.orig	2021-07-14 17:02:58 UTC
+++ src/vis.c
@@ -85,6 +85,10 @@ __weak_alias(strvisx,_strvisx)
 #include <stdio.h>
 #include <string.h>
 
+#ifndef MIN
+# define MIN(a,b) ((a) < (b) ? (a) : (b))
+#endif
+
 /*
  * The reason for going through the trouble to deal with character encodings
  * in vis(3), is that we use this to safe encode output of commands. This
