--- src/nfpcapd/packet_bpf.c.orig	2025-04-18 13:29:25 UTC
+++ src/nfpcapd/packet_bpf.c
@@ -37,6 +37,7 @@
 #endif
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <net/bpf.h>
 #include <net/if.h>
 #include <pthread.h>
@@ -49,7 +50,6 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 
