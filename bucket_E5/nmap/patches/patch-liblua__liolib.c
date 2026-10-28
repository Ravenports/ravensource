--- liblua/liolib.c.orig	2026-10-23 13:39:29 UTC
+++ liblua/liolib.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "lua.h"
 
