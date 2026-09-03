--- include/lame.h.orig	2026-07-11 07:30:24 UTC
+++ include/lame.h
@@ -44,7 +44,7 @@ typedef void (*lame_report_function)(con
 #define CDECL
 #endif
 
-#define DEPRECATED_OR_OBSOLETE_CODE_REMOVED 1
+#define DEPRECATED_OR_OBSOLETE_CODE_REMOVED 0
 
 typedef enum vbr_mode_e {
   vbr_off=0,
