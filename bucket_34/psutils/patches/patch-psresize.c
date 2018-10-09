--- psresize.c.orig	1997-03-11 22:53:03 UTC
+++ psresize.c
@@ -20,6 +20,10 @@
 #include "pserror.h"
 #include "patchlev.h"
 
+#if defined(LIBPAPER)
+#include <paper.h>
+#endif
+
 char *program ;
 int pages ;
 int verbose ;
@@ -46,7 +50,7 @@ static void argerror(void)
 #define MIN(x,y) ((x) > (y) ? (y) : (x))
 #define MAX(x,y) ((x) > (y) ? (x) : (y))
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    double scale, rscale;			/* page scale */
    double waste, rwaste;			/* amount wasted */
@@ -56,13 +60,21 @@ void main(int argc, char *argv[])
    double inheight = -1;
    Paper *paper;
    PageSpec *specs;
+   char *name = NULL;
 
+#if defined(LIBPAPER)
+	name = (char *)systempapername();
+	if (name == NULL)
+		name = (char *)defaultpapername();
+#else
 #ifdef PAPER
-   if ( (paper = findpaper(PAPER)) != (Paper *)0 ) {
-      inwidth = width = (double)PaperWidth(paper);
-      inheight = height = (double)PaperHeight(paper);
-   }
+	name = PAPER;
+#endif
 #endif
+	if ((paper = findpaper(name)) != NULL) {
+		inwidth = width = (double)PaperWidth(paper);
+		inheight = height = (double)PaperHeight(paper);
+	}
 
    vshift = hshift = 0;
    rotate = 0;
@@ -175,6 +187,6 @@ void main(int argc, char *argv[])
       
    pstops(1, 1, 0, specs, 0.0);		/* do page rearrangement */
 
-   exit(0);
+   return (0);
 }
 
