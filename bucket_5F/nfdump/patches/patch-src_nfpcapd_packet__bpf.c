--- src/nfpcapd/packet_bpf.c.orig	2026-09-07 15:40:59 UTC
+++ src/nfpcapd/packet_bpf.c
@@ -34,6 +34,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <inttypes.h>
 #include <net/bpf.h>
 #include <net/if.h>
@@ -48,7 +49,6 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 
