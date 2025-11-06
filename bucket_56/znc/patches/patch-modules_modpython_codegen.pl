Bad detect for swig 4.2.0+.  Just hardcode for now.

--- modules/modpython/codegen.pl.orig	2025-07-01 21:16:21 UTC
+++ modules/modpython/codegen.pl
@@ -64,7 +64,7 @@ namespace {
 // SWIG doesn't provide any good way to detect SWIG version (other than parsing
 // `swig -version`), but it also introduced SWIG_NULLPTR in 4.2.0.
 // So let's abuse that define to do different code for new SWIG.
-#ifdef SWIG_NULLPTR
+#if 1
 	// This is copied/adapted from SWIG 4.2.0 from pystrings.swg
 	inline int ZNC_SWIG_AsCharPtrAndSize(PyObject *obj, char** cptr, size_t* psize, int *alloc) {
 #if PY_VERSION_HEX>=0x03000000
