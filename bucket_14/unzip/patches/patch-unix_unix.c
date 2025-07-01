--- unix/unix.c.orig	2009-01-23 23:31:26 UTC
+++ unix/unix.c
@@ -30,6 +30,10 @@
 #define UNZIP_INTERNAL
 #include "unzip.h"
 
+#if defined(__sun__)
+#include <utime.h>
+#endif
+
 #ifdef SCO_XENIX
 #  define SYSNDIR
 #else  /* SCO Unix, AIX, DNIX, TI SysV, Coherent 4.x, ... */
@@ -610,7 +614,7 @@ int mapname(__G__ renamed)
                  * else allow 8-bit characters (e.g. UTF-8) in filenames:
                  */
                 if (uO.cflxflag ||
-                    (isprint(workch) || (128 <= workch && workch <= 254)))
+		    (isprint(workch) || (128 <= workch && workch <= 255)))
                     *pp++ = (char)workch;
         } /* end switch */
 
