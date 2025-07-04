--- cl/cl_main.c.orig	2007-11-18 16:41:42 UTC
+++ cl/cl_main.c
@@ -25,6 +25,7 @@ static const char sccsid[] = "$Id: cl_ma
 #include <string.h>
 #include <termios.h>
 #include <unistd.h>
+#include <ncurses/term.h>
 
 #include "../common/common.h"
 #include "../ip/extern.h"
