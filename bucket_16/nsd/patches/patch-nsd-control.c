--- nsd-control.c.orig	2022-05-13 06:56:14 UTC
+++ nsd-control.c
@@ -83,6 +83,10 @@ int zonec_parse_string(region_type* ATTR
 	return 0;
 }
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** Give nsd-control usage, and exit (1). */
 static void
 usage()
