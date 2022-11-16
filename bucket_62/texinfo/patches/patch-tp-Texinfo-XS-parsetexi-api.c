--- tp/Texinfo/XS/parsetexi/api.c.orig	2022-10-23 12:56:25 UTC
+++ tp/Texinfo/XS/parsetexi/api.c
@@ -30,7 +30,9 @@
 
 #undef context
 
+#if defined(HAVE_LIBINTL_H)
 #include <libintl.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
