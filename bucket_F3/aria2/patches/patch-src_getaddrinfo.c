--- src/getaddrinfo.c.orig	2023-11-15 09:49:41 UTC
+++ src/getaddrinfo.c
@@ -109,6 +109,7 @@
 #else    /* not STDC_HEADERS and not HAVE_STRING_H */
 #  include <strings.h>
 #endif /* not STDC_HEADERS and not HAVE_STRING_H */
+#include <strings.h>
 
 #ifdef HAVE_STDLIB_H
 #  include <stdlib.h>
