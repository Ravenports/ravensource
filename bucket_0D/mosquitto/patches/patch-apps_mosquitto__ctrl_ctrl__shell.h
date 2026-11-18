--- apps/mosquitto_ctrl/ctrl_shell.h.orig	2026-11-17 13:53:43 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.h
@@ -25,6 +25,7 @@ extern "C" {
 #include <cjson/cJSON.h>
 #include <stdarg.h>
 #include <stdbool.h>
+#include <stdarg.h>    // for va_list on NetBSD
 #include <stdio.h>
 
 extern const char *ANSI_URL;
