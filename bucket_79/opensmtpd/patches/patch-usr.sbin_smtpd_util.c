--- usr.sbin/smtpd/util.c.orig	2025-07-30 20:26:49 UTC
+++ usr.sbin/smtpd/util.c
@@ -44,6 +44,11 @@
 #include "smtpd.h"
 #include "log.h"
 
+#ifdef __sun
+#define __b64_ntop b64_ntop
+#define __b64_pton b64_pton
+#endif
+
 static int  parse_mailname_file(char *, size_t);
 
 int	tracing = 0;
