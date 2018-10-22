--- ext/bigdecimal/bigdecimal.c.orig	2018-01-31 13:38:59 UTC
+++ ext/bigdecimal/bigdecimal.c
@@ -102,29 +102,6 @@ static ID id_eq;
 # define RB_OBJ_STRING(obj) StringValueCStr(obj)
 #endif
 
-#ifndef HAVE_RB_RATIONAL_NUM
-static inline VALUE
-rb_rational_num(VALUE rat)
-{
-#ifdef HAVE_TYPE_STRUCT_RRATIONAL
-    return RRATIONAL(rat)->num;
-#else
-    return rb_funcall(rat, rb_intern("numerator"));
-#endif
-}
-#endif
-
-#ifndef HAVE_RB_RATIONAL_DEN
-static inline VALUE
-rb_rational_den(VALUE rat)
-{
-#ifdef HAVE_TYPE_STRUCT_RRATIONAL
-    return RRATIONAL(rat)->den;
-#else
-    return rb_funcall(rat, rb_intern("denominator"));
-#endif
-}
-#endif
 
 /*
  * ================== Ruby Interface part ==========================
