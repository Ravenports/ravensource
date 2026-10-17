--- liblua/liolib.c.orig	2026-08-05 21:12:13 UTC
+++ liblua/liolib.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "lua.h"
 
