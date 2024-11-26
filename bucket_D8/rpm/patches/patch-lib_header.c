--- lib/header.c.orig	2024-10-07 09:35:46 UTC
+++ lib/header.c
@@ -14,6 +14,9 @@
 #include <inttypes.h>
 #include <rpm/rpmtypes.h>
 #include <rpm/rpmstring.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+# include <arpa/inet.h>
+#endif
 #include "header_internal.h"
 #include "misc.h"			/* tag function proto */
 
