--- scribus/fonts/sfnt.cpp.orig	2021-09-18 21:58:29 UTC
+++ scribus/fonts/sfnt.cpp
@@ -19,9 +19,13 @@
 #include "scconfig.h"
 
 #include <harfbuzz/hb.h>
+# if HB_VERSION_ATLEAST(3, 0, 0)
+#  undef HAVE_HARFBUZZ_SUBSET
+# else
 #ifdef HAVE_HARFBUZZ_SUBSET
 #include <harfbuzz/hb-subset.h>
 #endif
+# endif
 
 struct HbBlobDeleter
 {
