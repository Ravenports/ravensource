--- liblua/liolib.c.orig	2018-10-17 00:30:14 UTC
+++ liblua/liolib.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "lua.h"
 
