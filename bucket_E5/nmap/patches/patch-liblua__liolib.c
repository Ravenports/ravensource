--- liblua/liolib.c.orig	2025-04-14 17:20:42 UTC
+++ liblua/liolib.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "lua.h"
 
