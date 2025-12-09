--- base/fapi_ft.c.orig	2025-09-09 09:36:39 UTC
+++ base/fapi_ft.c
@@ -60,6 +60,10 @@
 #include FT_MULTIPLE_MASTERS_H
 #include FT_TYPE1_TABLES_H
 
+#ifndef FT_CALLBACK_DEF
+#define FT_CALLBACK_DEF( x )  static x
+#endif
+
 /* Note: structure definitions here start with FF_, which stands for 'FAPI FreeType". */
 
 #define ft_emprintf(m,s) { outflush(m); emprintf(m, s); outflush(m); }
