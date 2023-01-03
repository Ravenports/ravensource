--- src/nfpcapd/pcapdump.c.orig	2022-12-24 12:30:59 UTC
+++ src/nfpcapd/pcapdump.c
@@ -40,6 +40,7 @@
 #include <string.h>
 #include <sys/param.h>
 #include <sys/types.h>
+#include <sys/stat.h> // for S_IFREG
 #include <time.h>
 #include <unistd.h>
 
