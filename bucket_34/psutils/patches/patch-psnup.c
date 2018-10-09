--- psnup.c.orig	1997-03-11 22:53:02 UTC
+++ psnup.c
@@ -28,6 +28,10 @@
 #include "pserror.h"
 #include "patchlev.h"
 
+#if defined(LIBPAPER)
+#include <paper.h>
+#endif
+
 char *program ;
 int pages ;
 int verbose ;
@@ -66,12 +70,12 @@ static int nextdiv(int n, int m)
    return (0);
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
-   int horiz, vert, rotate, column, flip, leftright, topbottom;
+   int horiz = 0, vert = 0, rotate = 0, column, flip, leftright, topbottom;
    int nup = 1;
    double draw = 0;				/* draw page borders */
-   double scale;				/* page scale */
+   double scale = 0;				/* page scale */
    double uscale = 0;				/* user supplied scale */
    double ppwid, pphgt;				/* paper dimensions */
    double margin, border;			/* paper & page margins */
@@ -79,13 +83,21 @@ void main(int argc, char *argv[])
    double iwidth, iheight ;			/* input paper size */
    double tolerance = 100000;			/* layout tolerance */
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
 #endif
+#endif
+	if ((paper = findpaper(name)) != NULL) {
+		width = (double)PaperWidth(paper);
+		height = (double)PaperHeight(paper);
+	}
 
    margin = border = vshift = hshift = column = flip = 0;
    leftright = topbottom = 1;
@@ -331,6 +343,6 @@ void main(int argc, char *argv[])
       pstops(nup, 1, 0, specs, draw);		/* do page rearrangement */
    }
 
-   exit(0);
+   return (0);
 }
 
