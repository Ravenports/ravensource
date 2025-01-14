--- popt/findme.c.orig	2006-11-09 00:57:55 UTC
+++ popt/findme.c
@@ -6,6 +6,9 @@
    file accompanying popt source distributions, available from 
    ftp://ftp.rpm.org/pub/rpm/dist. */
 
+#if defined(__linux__)
+#include "rsync.h"
+#endif
 #include "system.h"
 #include "findme.h"
 
