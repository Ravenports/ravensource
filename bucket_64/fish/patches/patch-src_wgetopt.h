--- src/wgetopt.h.orig	2017-12-22 16:16:29 UTC
+++ src/wgetopt.h
@@ -177,7 +177,7 @@ struct woption {
     int *flag;
     /// If \c flag is non-null, this is the value that flag will be set to. Otherwise, this is the
     /// return-value of the function call.
-    int val;
+    wchar_t val;
 };
 
 // Names for the values of the `has_arg' field of `struct option'.
