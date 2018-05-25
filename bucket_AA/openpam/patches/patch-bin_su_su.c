--- bin/su/su.c.orig	2017-04-30 21:34:49 UTC
+++ bin/su/su.c
@@ -54,6 +54,10 @@
 #include <security/pam_appl.h>
 #include <security/openpam.h>	/* for openpam_ttyconv() */
 
+#ifndef MAXHOSTNAMELEN
+#define MAXHOSTNAMELEN	256
+#endif
+
 extern char **environ;
 
 static pam_handle_t *pamh;
