--- lib/sfdpgen/PriorityQueue.c.orig	2020-04-08 07:51:57 UTC
+++ lib/sfdpgen/PriorityQueue.c
@@ -11,7 +11,11 @@
  * Contributors: See CVS logs. Details at http://www.graphviz.org/
  *************************************************************************/
 
+#if defined __DragonFly__ || defined __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "LinkedList.h"
 #include "PriorityQueue.h"
