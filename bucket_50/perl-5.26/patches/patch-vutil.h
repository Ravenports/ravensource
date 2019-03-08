--- vutil.h.orig	2018-03-01 12:20:34 UTC
+++ vutil.h
@@ -115,7 +115,7 @@ S_croak_xs_usage(pTHX_ const CV *const c
             Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
     } else {
         /* Pants. I don't think that it should be possible to get here. */
-        Perl_croak_nocontext("Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
+        Perl_croak_nocontext("Usage: CODE(0x%" UVxf ")(%s)", PTR2UV(cv), params);
     }
 }
 
