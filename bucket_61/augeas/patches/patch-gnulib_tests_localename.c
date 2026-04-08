--- gnulib/tests/localename.c.orig	2023-07-14 23:39:16 UTC
+++ gnulib/tests/localename.c
@@ -45,7 +45,7 @@
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
 /* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
+extern const char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
