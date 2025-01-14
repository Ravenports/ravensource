--- src/polkitbackend/polkitbackendauthority.c.orig	2025-01-13 14:54:22 UTC
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
