--- Src/Modules/watch.c.orig	2022-05-08 06:18:22 UTC
+++ Src/Modules/watch.c
@@ -30,9 +30,21 @@
 #include "watch.mdh"
 
 /* Headers for utmp/utmpx structures */
+
+#    if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__MidnightBSD__)
+# if defined(HAVE_UTMP_H) && !defined(HAVE_UTMPX_H)
+#  include <utmp.h>
+# else
+#  undef HAVE_STRUCT_UTMP
+#  undef HAVE_STRUCT_UTMP_UT_HOST
+# endif
+#    else
+
 #ifdef HAVE_UTMP_H
 # include <utmp.h>
 #endif
+
+#    endif
 #ifdef HAVE_UTMPX_H
 # include <utmpx.h>
 #endif
