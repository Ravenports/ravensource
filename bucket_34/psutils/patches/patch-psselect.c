--- psselect.c.orig	1997-03-11 22:53:03 UTC
+++ psselect.c
@@ -91,7 +91,7 @@ static PageRange *addrange(char *str, Pa
 }
 
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    int currentpg, maxpage = 0;
    int even = 0, odd = 0, reverse = 0;
@@ -235,5 +235,5 @@ void main(int argc, char *argv[])
    }
    writetrailer();
 
-   exit(0);
+   return (0);
 }
