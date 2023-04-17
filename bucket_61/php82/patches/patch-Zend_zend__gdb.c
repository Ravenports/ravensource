--- Zend/zend_gdb.c.orig	2023-04-11 16:16:23 UTC
+++ Zend/zend_gdb.c
@@ -25,7 +25,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#if defined(__FreeBSD__)
+#if defined(__MidnightBSD__)
+# include <sys/user.h>
+#elif defined(__FreeBSD__)
 # include <sys/user.h>
 # include <libutil.h>
 #endif
