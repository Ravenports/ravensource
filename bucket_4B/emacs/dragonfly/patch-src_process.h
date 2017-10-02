--- src/process.h.orig	2017-04-14 15:02:47 UTC
+++ src/process.h
@@ -24,6 +24,7 @@ along with GNU Emacs.  If not, see <http
 #endif
 
 #include <unistd.h>
+#include <sys/signal.h>
 
 #ifdef HAVE_GNUTLS
 #include "gnutls.h"
