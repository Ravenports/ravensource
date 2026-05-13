--- erts/emulator/drivers/common/inet_drv.c.orig	2026-05-11 10:28:08 UTC
+++ erts/emulator/drivers/common/inet_drv.c
@@ -24,6 +24,10 @@
 #include "config.h"
 #endif
 
+#if defined(__sun)
+#define  _XPG4_2
+#define  __EXTENSIONS__
+#endif
 
 /* If we HAVE_SCTP_H and Solaris, we need to define the following in
  * order to get SCTP working:
@@ -31,8 +35,6 @@
 #if (defined(HAVE_SCTP_H) && defined(__sun) && defined(__SVR4))
 #define  SOLARIS10    1
 /* WARNING: This is not quite correct, it may also be Solaris 11! */
-#define  _XPG4_2
-#define  __EXTENSIONS__
 #endif
 
 #include <stdio.h>
