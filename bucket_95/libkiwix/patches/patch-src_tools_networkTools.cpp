--- src/tools/networkTools.cpp.orig	2024-10-09 17:18:52 UTC
+++ src/tools/networkTools.cpp
@@ -44,6 +44,7 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #endif
 
 #ifdef __HAIKU__
