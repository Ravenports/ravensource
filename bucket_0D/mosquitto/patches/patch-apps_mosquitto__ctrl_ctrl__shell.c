--- apps/mosquitto_ctrl/ctrl_shell.c.orig	2026-11-17 13:53:43 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.c
@@ -34,6 +34,7 @@ Contributors:
 #ifndef WIN32
 #  include <netinet/in.h>
 #  include <unistd.h>
+#  include <netinet/in.h>
 #endif
 
 #include "ctrl_shell.h"
