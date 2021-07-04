--- tp/Texinfo/XS/parsetexi/api.c.orig	2021-03-12 20:48:49 UTC
+++ tp/Texinfo/XS/parsetexi/api.c
@@ -25,7 +25,9 @@
 
 #undef context
 
+#if defined(HAVE_LIBINTL_H)
 #include <libintl.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
