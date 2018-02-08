--- util/cairo-missing/getline.c.orig	2017-12-04 22:24:46 UTC
+++ util/cairo-missing/getline.c
@@ -87,4 +87,6 @@ getline (char	**lineptr,
     return ret;
 }
 #undef GETLINE_BUFFER_SIZE
+#else
+int solaris_ld_requires_at_least_one_symbol = 0;
 #endif
