--- psbook.c.orig	1997-03-11 22:53:01 UTC
+++ psbook.c
@@ -32,7 +32,7 @@ static void usage(void)
 }
 
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
    int signature = 0;
    int currentpg, maxpage;
@@ -107,5 +107,5 @@ void main(int argc, char *argv[])
    }
    writetrailer();
 
-   exit(0);
+   return (0);
 }
