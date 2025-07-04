--- main.c.orig	2024-02-05 01:55:23 UTC
+++ main.c
@@ -57,6 +57,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined __sun__
+#include <sys/termios.h>
+#endif
 
 #include "ed.h"
 
