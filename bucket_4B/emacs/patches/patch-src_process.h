--- src/process.h.orig	2025-02-17 22:38:58 UTC
+++ src/process.h
@@ -24,6 +24,9 @@ along with GNU Emacs.  If not, see <http
 #endif
 
 #include <unistd.h>
+#ifdef __DragonFly__
+#include <sys/signal.h>
+#endif
 
 #ifdef HAVE_GNUTLS
 #include "gnutls.h"
