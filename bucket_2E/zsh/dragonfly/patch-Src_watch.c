--- Src/watch.c.orig	2019-12-13 22:41:30 UTC
+++ Src/watch.c
@@ -30,8 +30,11 @@
 #include "zsh.mdh"
 
 /* Headers for utmp/utmpx structures */
-#ifdef HAVE_UTMP_H
+#if defined(HAVE_UTMP_H) && !defined(HAVE_UTMPX_H)
 # include <utmp.h>
+#else
+# undef HAVE_STRUCT_UTMP
+# undef HAVE_STRUCT_UTMP_UT_HOST
 #endif
 #ifdef HAVE_UTMPX_H
 # include <utmpx.h>
