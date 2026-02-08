--- apps/mosquitto_ctrl/ctrl_shell.c.orig	2026-02-04 22:33:13 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.c
@@ -33,6 +33,7 @@ Contributors:
 
 #ifndef WIN32
 #  include <unistd.h>
+#  include <netinet/in.h>
 #endif
 
 #include "ctrl_shell.h"
