--- src/libraw_cxx.cpp.orig	Wed May  6 16:40:30 2020
+++ src/libraw_cxx.cpp	Wed May  6 16:41:00 2020
@@ -6183,6 +6183,9 @@
   _x3f_data = x3f;
 
   x3f_header_t *H = NULL;
+#ifdef DS
+#undef DS
+#endif
   x3f_directory_section_t *DS = NULL;
 
   H = &x3f->header;
