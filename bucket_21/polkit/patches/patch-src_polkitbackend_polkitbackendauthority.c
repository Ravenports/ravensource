--- src/polkitbackend/polkitbackendauthority.c.orig	2026-10-15 15:22:30 UTC
+++ src/polkitbackend/polkitbackendauthority.c
@@ -24,6 +24,9 @@
 #include <string.h>
 #include <syslog.h>
 #include <stdarg.h>
+#ifdef HAVE_SOLARIS
+#include <netinet/ip_compat.h>
+#endif
 
 #include <polkit/polkit.h>
 #include <polkit/polkitprivate.h>
