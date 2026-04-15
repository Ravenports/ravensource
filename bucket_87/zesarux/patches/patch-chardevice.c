--- chardevice.c.orig	2025-09-25 16:14:00 UTC
+++ chardevice.c
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
+#include <string.h> // for memset for FD_ZERO
 #include <fcntl.h>
 
 #ifndef MINGW
@@ -245,4 +246,4 @@ struct termios options;
     }
 #endif
 
-}
\ No newline at end of file
+}
