--- nsd-control.c.orig	2020-12-01 12:25:39 UTC
+++ nsd-control.c
@@ -67,6 +67,10 @@ static void usage(void) ATTR_NORETURN;
 static void ssl_err(const char* s) ATTR_NORETURN;
 static void ssl_path_err(const char* s, const char *path) ATTR_NORETURN;
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** Give nsd-control usage, and exit (1). */
 static void
 usage()
