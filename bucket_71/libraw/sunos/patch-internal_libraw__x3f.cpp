--- internal/libraw_x3f.cpp.orig	Tue Aug 20 19:34:30 2019
+++ internal/libraw_x3f.cpp	Wed May  6 17:23:27 2020
@@ -707,6 +707,9 @@
 /* --------------------------------------------------------------------- */
 /* Creating a new x3f structure from file                                */
 /* --------------------------------------------------------------------- */
+#ifdef DS
+#undef DS
+#endif
 
 /* extern */ x3f_t *x3f_new_from_file(LibRaw_abstract_datastream *infile)
 {
