--- src/fcint.h.orig	2021-12-03 10:48:08 UTC
+++ src/fcint.h
@@ -128,13 +128,7 @@ extern pfnSHGetFolderPathA pSHGetFolderP
 #endif
 
 /* NLS */
-#ifdef ENABLE_NLS
-#include <libintl.h>
-#define _(x)		(dgettext(GETTEXT_PACKAGE, x))
-#else
-#define dgettext(d, s)	(s)
 #define _(x)		(x)
-#endif
 
 #define N_(x)	x
 
