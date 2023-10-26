--- tp/Texinfo/XS/parsetexi/api.c.orig	2023-10-15 11:39:58 UTC
+++ tp/Texinfo/XS/parsetexi/api.c
@@ -30,7 +30,9 @@
 
 #undef context
 
+#if defined(HAVE_LIBINTL_H)
 #include <libintl.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
