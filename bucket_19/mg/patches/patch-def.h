For bcopy on SunOS

--- def.h.orig	2026-07-19 15:45:19 UTC
+++ def.h
@@ -12,6 +12,7 @@
 
 #include <sys/types.h>
 #include <unistd.h>
+#include <strings.h>
 
 #include	"chrdef.h"
 
