--- filter/gstoraster.c.orig	2023-01-25 01:41:08 UTC
+++ filter/gstoraster.c
@@ -50,6 +50,8 @@ MIT Open Source License  -  http://www.o
 #include <errno.h>
 #include "pdf.h"
 
+#define execvpe(a, b, c) execvp(a, b)
+
 #define PDF_MAX_CHECK_COMMENT_LINES	20
 
 typedef enum {
