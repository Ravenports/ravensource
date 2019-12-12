--- src/polkitbackend/polkitbackendauthority.c.orig	2018-05-31 11:52:53 UTC
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
