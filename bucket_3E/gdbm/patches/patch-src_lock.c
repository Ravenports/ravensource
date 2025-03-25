--- src/lock.c.orig	2025-03-06 16:24:09 UTC
+++ src/lock.c
@@ -43,6 +43,10 @@
 # endif
 #endif
 
+# ifndef ETIME
+#  define ETIME ETIMEDOUT 
+# endif
+
 #if defined(F_SETLK) && defined(F_RDLCK) && defined(F_WRLCK)
 # define HAVE_FCNTL_LOCK 1
 #else
