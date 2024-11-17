--- execunix.c.orig	2019-06-20 23:12:56 UTC
+++ execunix.c
@@ -51,9 +51,8 @@
 # include <process.h>
 # endif
 
-# ifdef OS_MACOSX
 # include <unistd.h>
-# endif
+# include <sys/wait.h>
 
 # ifdef OS_NT 
 # define USE_EXECNT
