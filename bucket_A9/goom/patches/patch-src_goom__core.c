--- src/goom_core.c.orig	2005-02-07 13:46:41 UTC
+++ src/goom_core.c
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>  // for bzero
 #include <inttypes.h>
 
 #include "goom.h"
