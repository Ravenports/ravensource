--- bin/su/su.c.orig	2022-10-02 14:45:45 UTC
+++ bin/su/su.c
@@ -52,6 +52,10 @@
 #include <security/pam_appl.h>
 #include <security/openpam.h>	/* for openpam_ttyconv() */
 
+#ifndef MAXHOSTNAMELEN
+#define MAXHOSTNAMELEN	256
+#endif
+
 extern char **environ;
 
 static pam_handle_t *pamh;
