--- src/polkitbackend/polkitbackendauthority.c.orig	2022-10-26 12:12:24 UTC
+++ src/polkitbackend/polkitbackendauthority.c
@@ -25,6 +25,9 @@
 #include <string.h>
 #include <syslog.h>
 #include <stdarg.h>
+#ifdef HAVE_SOLARIS
+#include <netinet/ip_compat.h>
+#endif
 
 #include <polkit/polkit.h>
 #include <polkit/polkitprivate.h>
