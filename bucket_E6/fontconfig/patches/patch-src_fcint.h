--- src/fcint.h.orig	2026-11-18 11:53:03 UTC
+++ src/fcint.h
@@ -139,15 +139,7 @@ extern pfnSHGetFolderPathA          pSHG
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
 
