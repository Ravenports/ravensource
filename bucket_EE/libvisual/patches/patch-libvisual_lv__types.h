--- libvisual/lv_types.h.orig	2023-03-20 02:04:17 UTC
+++ libvisual/lv_types.h
@@ -26,7 +26,7 @@
 
 #include <libvisual/lv_defines.h>
 
-#if defined(VISUAL_OS_WIN32)
+#if defined(VISUAL_OS_WIN32) || defined(__linux__)
 #include <stdint.h>
 #else
 #include <sys/types.h>
@@ -38,7 +38,7 @@ VISUAL_BEGIN_DECLS
 
 #define VISUAL_TABLESIZE(table)			(sizeof (table) / sizeof (table[0]))
 
-#if !defined(VISUAL_OS_WIN32)
+#if 0
 #ifndef uint8_t
 #define uint8_t		u_int8_t
 #endif
