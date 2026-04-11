--- usr.sbin/smtpd/mta_session.c.orig	2025-07-30 20:26:49 UTC
+++ usr.sbin/smtpd/mta_session.c
@@ -35,6 +35,7 @@
 #include <time.h>
 #include <tls.h>
 #include <unistd.h>
+#include <strings.h>
 
 #include "smtpd.h"
 #include "log.h"
