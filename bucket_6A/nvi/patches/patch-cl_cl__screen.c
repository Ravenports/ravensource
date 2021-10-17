--- cl/cl_screen.c.orig	2007-11-18 16:41:42 UTC
+++ cl/cl_screen.c
@@ -17,6 +17,7 @@ static const char sccsid[] = "$Id: cl_sc
 #include <sys/queue.h>
 
 #include <bitstring.h>
+#include <term.h>
 #include <errno.h>
 #include <signal.h>
 #include <stdio.h>
