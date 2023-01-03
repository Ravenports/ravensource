--- src/nfpcapd/packet_bpf.c.orig	2022-12-24 12:30:59 UTC
+++ src/nfpcapd/packet_bpf.c
@@ -30,6 +30,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <net/bpf.h>
 #include <net/if.h>
 #include <pthread.h>
@@ -42,7 +43,6 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 
