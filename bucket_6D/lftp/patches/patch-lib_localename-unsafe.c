--- lib/localename-unsafe.c.orig	2024-11-08 09:43:25 UTC
+++ lib/localename-unsafe.c
@@ -48,7 +48,7 @@
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
 /* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
+extern const char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
