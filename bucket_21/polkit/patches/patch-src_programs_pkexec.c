Provide solaris header for LOG_AUTHPRIV

--- src/programs/pkexec.c.orig	2025-12-17 16:14:53 UTC
+++ src/programs/pkexec.c
@@ -47,6 +47,9 @@
 
 #include <syslog.h>
 #include <stdarg.h>
+#ifdef HAVE_SOLARIS
+#include <netinet/ip_compat.h>
+#endif
 
 #include <polkit/polkit.h>
 #define POLKIT_AGENT_I_KNOW_API_IS_SUBJECT_TO_CHANGE
