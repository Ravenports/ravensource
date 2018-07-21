--- dbind/dbind-any.c.orig	2018-03-13 00:30:12 UTC
+++ dbind/dbind-any.c
@@ -17,6 +17,10 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#ifdef __sun__
+#define __EXTENSIONS__
+#endif
+
 /* type driven marshalling */
 #include <stdio.h>
 #include <glib.h>
