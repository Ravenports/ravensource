--- nsd-control.c.orig	2022-11-10 08:11:36 UTC
+++ nsd-control.c
@@ -84,6 +84,10 @@ int zonec_parse_string(region_type* ATTR
 	return 0;
 }
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** Give nsd-control usage, and exit (1). */
 static void
 usage()
