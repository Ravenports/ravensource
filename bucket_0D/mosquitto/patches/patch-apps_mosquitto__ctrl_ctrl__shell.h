--- apps/mosquitto_ctrl/ctrl_shell.h.orig	2026-02-04 22:33:13 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.h
@@ -24,6 +24,7 @@ extern "C" {
 
 #include <cjson/cJSON.h>
 #include <stdbool.h>
+#include <stdarg.h>    // for va_list on NetBSD
 #include <stdio.h>
 
 extern const char *ANSI_URL;
