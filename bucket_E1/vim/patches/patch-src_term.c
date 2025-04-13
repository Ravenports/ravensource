--- src/term.c.orig	2025-04-12 16:39:16 UTC
+++ src/term.c
@@ -30,6 +30,7 @@
 #  include <termios.h>	    // seems to be required for some Linux
 # endif
 # ifdef HAVE_TERMCAP_H
+#  include <term.h>
 #  include <termcap.h>
 # endif
 
