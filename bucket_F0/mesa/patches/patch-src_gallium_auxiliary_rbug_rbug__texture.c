--- src/gallium/auxiliary/rbug/rbug_texture.c.orig	2019-10-24 16:13:03 UTC
+++ src/gallium/auxiliary/rbug/rbug_texture.c
@@ -34,6 +34,10 @@
  * Functions ending with _reply are replies to requests.
  */
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "rbug_internal.h"
 #include "rbug_texture.h"
 
