--- timidity/vorbis_a.c.orig	2008-04-01 02:35:08 UTC
+++ timidity/vorbis_a.c
@@ -28,6 +28,8 @@
 #include "interface.h"
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
+#include <time.h>
 
 #ifdef AU_VORBIS
 
