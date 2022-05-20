--- Src/Modules/watch.c.orig	2022-05-20 19:05:18.932447000 +0200
+++ Src/Modules/watch.c	2022-05-20 19:06:22.250719000 +0200
@@ -30,8 +30,11 @@
 #include "watch.mdh"
 
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
