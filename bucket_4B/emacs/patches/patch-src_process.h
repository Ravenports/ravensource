--- src/process.h.orig	2025-01-04 11:05:30 UTC
+++ src/process.h
@@ -24,6 +24,9 @@ along with GNU Emacs.  If not, see <http
 #endif
 
 #include <unistd.h>
+#ifdef __DragonFly__
+#include <sys/signal.h>
+#endif
 
 #ifdef HAVE_GNUTLS
 #include "gnutls.h"
