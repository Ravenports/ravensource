--- src/fcint.h.orig	2025-06-27 03:12:04 UTC
+++ src/fcint.h
@@ -134,15 +134,7 @@ extern pfnSHGetFolderPathA          pSHG
 #endif
 
 /* NLS */
-#ifdef ENABLE_NLS
-#  include <libintl.h>
-#  define _(x) (dgettext (GETTEXT_PACKAGE, x))
-#else
-/* dgettext macro must be defined after existing declarations */
-#  include <locale.h>
-#  define dgettext(d, s) (s)
 #  define _(x)           (x)
-#endif
 
 #define N_(x) x
 
