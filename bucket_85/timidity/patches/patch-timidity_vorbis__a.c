--- timidity/vorbis_a.c.orig	2008-04-01 02:35:08 UTC
+++ timidity/vorbis_a.c
@@ -27,6 +27,7 @@
 #endif /* HAVE_CONFIG_H */
 #include "interface.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #ifdef AU_VORBIS
