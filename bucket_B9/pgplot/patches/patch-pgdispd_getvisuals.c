--- pgdispd/getvisuals.c.orig	1993-05-10 00:42:46 UTC
+++ pgdispd/getvisuals.c
@@ -30,6 +30,7 @@
 #include "messages.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #define MAX_DEPTH	24	/* the maximum visual depth to use */
 
