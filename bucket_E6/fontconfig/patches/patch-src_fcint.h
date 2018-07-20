--- src/fcint.h.orig	2018-02-04 10:20:56 UTC
+++ src/fcint.h
@@ -114,13 +114,7 @@ extern pfnSHGetFolderPathA pSHGetFolderP
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
 
