--- src/nfpcapd/nfpcapd.c.orig	2022-12-24 12:30:59 UTC
+++ src/nfpcapd/nfpcapd.c
@@ -33,6 +33,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <libgen.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
@@ -52,7 +53,6 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
