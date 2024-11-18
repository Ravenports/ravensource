--- exp_chan.c.orig	2018-02-02 19:15:52 UTC
+++ exp_chan.c
@@ -35,6 +35,7 @@
 #include "exp_prog.h"
 #include "exp_command.h"
 #include "exp_log.h"
+#include "exp_event.h"
 #include "tcldbg.h" /* Dbg_StdinMode */
 
 extern int		expSetBlockModeProc _ANSI_ARGS_((int fd, int mode));
@@ -58,7 +59,7 @@ static int		ExpGetHandleProc _ANSI_ARGS_
 
 Tcl_ChannelType expChannelType = {
     "exp",				/* Type name. */
-    ExpBlockModeProc,			/* Set blocking/nonblocking mode.*/
+    (struct Tcl_ChannelTypeVersion_ *)ExpBlockModeProc,	 /* Set blocking/nonblocking mode.*/
     ExpCloseProc,			/* Close proc. */
     ExpInputProc,			/* Input proc. */
     ExpOutputProc,			/* Output proc. */
