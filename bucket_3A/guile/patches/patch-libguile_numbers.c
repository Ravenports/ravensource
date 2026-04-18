--- libguile/numbers.c.orig	2024-04-15 17:58:25 UTC
+++ libguile/numbers.c
@@ -6113,6 +6113,8 @@ scm_c_make_polar (double mag, double ang
      details.  */
 #if (defined HAVE_SINCOS) && (defined __GLIBC__) && (defined _GNU_SOURCE)
   sincos (ang, &s, &c);
+#elif defined(__sun)
+  sincos (ang, &s, &c);
 #elif (defined HAVE___SINCOS)
   __sincos (ang, &s, &c);
 #else
