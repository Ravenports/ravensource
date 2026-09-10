--- chardevice.c.orig	2026-06-09 16:37:08 UTC
+++ chardevice.c
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
+#include <string.h>
 #include <fcntl.h>
 
 #include "compileoptions.h"
@@ -269,4 +270,4 @@ struct termios options;
     #endif
 #endif
 
-}
\ No newline at end of file
+}
