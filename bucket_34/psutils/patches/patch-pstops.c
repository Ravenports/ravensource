--- pstops.c.orig	1997-03-11 22:53:04 UTC
+++ pstops.c
@@ -13,6 +13,10 @@
 #include "pserror.h"
 #include "patchlev.h"
 
+#if defined(LIBPAPER)
+#include <paper.h>
+#endif
+
 char *program ;
 int pages ;
 int verbose ;
@@ -112,19 +116,27 @@ static PageSpec *parsespecs(char *str)
    return (head);
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    PageSpec *specs = NULL;
    int nobinding = 0;
    double draw = 0;
    Paper *paper;
+   char *name;
 
+#if defined(LIBPAPER)
+	name = (char *)systempapername();
+	if (name == NULL)
+		name = (char *)defaultpapername();
+#else
 #ifdef PAPER
-   if ( (paper = findpaper(PAPER)) != (Paper *)0 ) {
-      width = (double)PaperWidth(paper);
-      height = (double)PaperHeight(paper);
-   }
+	name = PAPER;
+#endif
 #endif
+	if ((paper = findpaper(name)) != NULL) {
+		width = (double)PaperWidth(paper);
+		height = (double)PaperHeight(paper);
+	}
 
    infile = stdin;
    outfile = stdout;
@@ -194,5 +206,5 @@ void main(int argc, char *argv[])
 
    pstops(modulo, pagesperspec, nobinding, specs, draw);
 
-   exit(0);
+   return (0);
 }
