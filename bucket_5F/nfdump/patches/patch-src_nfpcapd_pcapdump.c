--- src/nfpcapd/pcapdump.c.orig	2025-11-09 17:02:56 UTC
+++ src/nfpcapd/pcapdump.c
@@ -41,6 +41,7 @@
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/stat.h> // for S_IFREG
 #include <time.h>
 #include <unistd.h>
 
