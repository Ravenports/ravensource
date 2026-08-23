--- lib/header.cc.orig	2026-07-16 13:34:05 UTC
+++ lib/header.cc
@@ -15,6 +15,9 @@
 #include <atomic>
 #include <rpm/rpmtypes.h>
 #include <rpm/rpmstring.h>
+#if defined(__FreeBSD__)
+#include <arpa/inet.h>                  /* for ntohl */
+#endif
 #include "header_internal.hh"
 #include "misc.hh"			/* tag function proto */
 
