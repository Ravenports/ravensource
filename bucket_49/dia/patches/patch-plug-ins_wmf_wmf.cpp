--- plug-ins/wmf/wmf.cpp.orig	2014-08-24 15:46:01 UTC
+++ plug-ins/wmf/wmf.cpp
@@ -54,15 +54,17 @@ typedef W32::LOGFONTW LOGFONTW;
 
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
