--- ast/pointset.h.orig	2014-09-11 03:05:19 UTC
+++ ast/pointset.h
@@ -203,7 +203,7 @@
 #  endif
 #endif
 
-#if !HAVE_DECL_ISFINITE
+#if 0
 #  if HAVE_ISFINITE
      /* Seems that math.h does not include a prototype for isfinite */
      int isfinite( double );
