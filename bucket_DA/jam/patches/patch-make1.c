--- make1.c.orig	2019-06-20 23:12:56 UTC
+++ make1.c
@@ -49,6 +49,7 @@
  * 12/03/02 (seiwald) - fix odd includes support by grafting them onto depends
  */
 
+# include <unistd.h>
 # include "jam.h"
 
 # include "lists.h"
