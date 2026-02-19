--- apps/mosquitto_ctrl/ctrl_shell.h.orig	2026-02-09 09:29:46 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.h
@@ -25,6 +25,7 @@ extern "C" {
 #include <cjson/cJSON.h>
 #include <stdarg.h>
 #include <stdbool.h>
+#include <stdarg.h>    // for va_list on NetBSD
 #include <stdio.h>
 
 extern const char *ANSI_URL;
