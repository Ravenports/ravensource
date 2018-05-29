--- src/process.h.orig	2018-04-23 14:18:03 UTC
+++ src/process.h
@@ -24,6 +24,7 @@ along with GNU Emacs.  If not, see <http
 #endif
 
 #include <unistd.h>
+#include <sys/signal.h>
 
 #ifdef HAVE_GNUTLS
 #include "gnutls.h"
