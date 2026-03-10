For bcopy on SunOS

--- def.h.orig	2024-07-09 15:39:50 UTC
+++ def.h
@@ -12,6 +12,7 @@
 
 #include <sys/types.h>
 #include <unistd.h>
+#include <strings.h>
 
 #include	"chrdef.h"
 
