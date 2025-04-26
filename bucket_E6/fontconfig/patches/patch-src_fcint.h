--- src/fcint.h.orig	2025-04-11 06:47:01 UTC
+++ src/fcint.h
@@ -130,13 +130,7 @@ extern pfnSHGetFolderPathA          pSHG
 #endif
 
 /* NLS */
-#ifdef ENABLE_NLS
-#  include <libintl.h>
-#  define _(x) (dgettext (GETTEXT_PACKAGE, x))
-#else
-#  define dgettext(d, s) (s)
 #  define _(x)           (x)
-#endif
 
 #define N_(x) x
 
