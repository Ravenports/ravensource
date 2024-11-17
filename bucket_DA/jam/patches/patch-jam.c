--- jam.c.orig	2019-06-20 23:12:56 UTC
+++ jam.c
@@ -166,7 +166,7 @@ extern char **environ;
 # endif
 # endif
 
-main( int argc, char **argv, char **arg_environ )
+int main( int argc, char **argv, char **arg_environ )
 {
 	int		n;
 	const char	*s;
