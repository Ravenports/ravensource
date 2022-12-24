--- orc/orccodemem.c.orig	2022-10-31 18:16:26 UTC
+++ orc/orccodemem.c
@@ -1,6 +1,7 @@
 
 #include "config.h"
 
+#include <errno.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
