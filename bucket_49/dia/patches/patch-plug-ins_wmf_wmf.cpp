--- plug-ins/wmf/wmf.cpp.orig	2014-08-24 17:46:01.000000000 +0200
+++ plug-ins/wmf/wmf.cpp	2022-12-31 14:35:14.378917000 +0100
@@ -54,15 +54,17 @@
 
 #elif HAVE_LIBEMF
   namespace W32 {
-#  include <emf.h>
+#  include <libEMF/emf.h>
   }
 #else
 #  include "wmf_gdi.h"
 #  define SAVE_EMF
 #endif
 
+#ifdef G_OS_WIN32
 /* force linking with gdi32 */
 #pragma comment( lib, "gdi32" )
+#endif
 
 
 // #define SAVE_EMF
