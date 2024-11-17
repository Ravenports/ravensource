--- mkjambase.c.orig	2019-06-20 23:12:56 UTC
+++ mkjambase.c
@@ -24,6 +24,7 @@
 # include <stdio.h>
 # include <string.h>
 
+int
 main( int argc, char **argv, char **envp )
 {
 	char buf[ 1024 ];
