Needed on FreeBSD (DragonFly is fine)

--- src/utils.c.orig	2025-12-21 18:43:42 UTC
+++ src/utils.c
@@ -1,4 +1,5 @@
 #ifndef _WIN32
+#  include <signal.h>
 #  include <sys/wait.h>
 #endif
 
