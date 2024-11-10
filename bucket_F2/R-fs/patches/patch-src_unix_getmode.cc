--- src/unix/getmode.cc.orig	2024-10-25 10:46:21 UTC
+++ src/unix/getmode.cc
@@ -2,6 +2,7 @@
 #include "utils.h"
 
 #if (defined(__APPLE__) && defined(__MACH__)) || defined(__OpenBSD__) ||       \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__NetBSD__)
 #include <string.h> /* for strmode */
 #include <unistd.h> /* for getmode / setmode */
