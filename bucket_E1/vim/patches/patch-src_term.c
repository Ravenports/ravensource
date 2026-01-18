--- src/term.c.orig	2026-01-10 18:14:13 UTC
+++ src/term.c
@@ -30,6 +30,7 @@
 #  include <termios.h>	    // seems to be required for some Linux
 # endif
 # ifdef HAVE_TERMCAP_H
+#  include <term.h>
 #  include <termcap.h>
 # endif
 
