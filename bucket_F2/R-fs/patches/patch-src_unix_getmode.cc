--- src/unix/getmode.cc.orig	2021-12-01 21:54:08 UTC
+++ src/unix/getmode.cc
@@ -2,6 +2,7 @@
 #include "utils.h"
 
 #if (defined(__APPLE__) && defined(__MACH__)) || defined(__OpenBSD__) ||       \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__NetBSD__)
 #include <string.h> /* for strmode */
 #include <unistd.h> /* for getmode / setmode */
