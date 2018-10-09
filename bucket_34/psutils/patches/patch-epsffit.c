--- epsffit.c.orig	1997-03-11 22:52:52 UTC
+++ epsffit.c
@@ -39,10 +39,10 @@ static void usage(void)
    exit(1);
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
    int bbfound = 0;              /* %%BoundingBox: found */
-   int urx, ury, llx, lly;
+   int urx = 0, ury = 0, llx = 0, lly = 0;
    int furx, fury, fllx, flly;
    int showpage = 0, centre = 0, rotate = 0, aspect = 0, maximise = 0;
    char buf[BUFSIZ];
@@ -185,5 +185,5 @@ void main(int argc, char **argv)
    } else
       message(FATAL, "no %%%%BoundingBox:\n");
 
-   exit(0);
+   return (0);
 }
