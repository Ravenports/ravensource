--- bin/cbsdsh/src/cbsd_fwatch.c.orig	2026-04-12 13:46:35 UTC
+++ bin/cbsdsh/src/cbsd_fwatch.c
@@ -191,7 +191,7 @@ cbsd_fwatchcmd(int argc, char *argv[])
 	return 0;
 }
 
-#if defined(__DragonFly__) || defined(__NetBSD__)
+#if defined(__NetBSD__)
 // temporary noop function for non-FreeBSD
 int
 cbsdjlscmd(int argc, char **argv)
