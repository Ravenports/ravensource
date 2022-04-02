--- base/fapi_ft.c.orig	2022-03-29 07:30:53 UTC
+++ base/fapi_ft.c
@@ -61,6 +61,10 @@
 #include FT_TYPE1_TABLES_H
 #include FT_SIZES_H
 
+#ifndef FT_CALLBACK_DEF
+#define FT_CALLBACK_DEF( x )  static x
+#endif
+
 /* Note: structure definitions here start with FF_, which stands for 'FAPI FreeType". */
 
 #define ft_emprintf(m,s) { outflush(m); emprintf(m, s); outflush(m); }
