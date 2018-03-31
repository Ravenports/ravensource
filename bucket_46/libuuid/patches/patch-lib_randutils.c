O_CLOEXEC is not available on every platform (e.g. MacOS X < 10.7). It
was introduced in POSIX 2008.

--- lib/randutils.c.orig	2018-03-20 13:16:23 UTC
+++ lib/randutils.c
@@ -74,6 +74,10 @@ static void crank_random(void)
 		rand();
 }
 
+#if !defined(O_CLOEXEC)
+#define O_CLOEXEC 0
+#endif
+
 int random_get_fd(void)
 {
 	int i, fd;
