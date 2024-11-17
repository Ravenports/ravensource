--- timidity/flac_a.c.orig	2014-05-24 11:00:20 UTC
+++ timidity/flac_a.c
@@ -33,6 +33,7 @@
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
 #include <fcntl.h>
+#include <string.h>
 #include "common.h"
 
 #ifdef __W32__
