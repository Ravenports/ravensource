--- test/midifile.c.orig	2020-06-18 17:24:32 UTC
+++ test/midifile.c
@@ -71,7 +71,7 @@
 #endif
 
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 
 #include <string.h>
 /*void exit(), free();*/
@@ -328,7 +328,7 @@ readtrack ()			/* read a track chunk */
 
   if (Mf_interactive)
     {
-      Mf_toberead = MAXINT;
+      Mf_toberead = INT_MAX;
     }
   else
     {
