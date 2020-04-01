--- file.c.orig	2020-03-31 10:44:55 UTC
+++ file.c
@@ -28,7 +28,6 @@
 #   define API_AVAILABLE(...)
 #   define API_DEPRECATED(...)
 # endif
-#include <CoreFoundation/CFString.h>
 #endif
 
 #include "id.h"
@@ -251,7 +250,7 @@ rb_str_encode_ospath(VALUE path)
     return path;
 }
 
-#ifdef __APPLE__
+#if 0
 # define NORMALIZE_UTF8PATH 1
 static VALUE
 rb_str_append_normalized_ospath(VALUE str, const char *ptr, long len)
@@ -3836,7 +3835,7 @@ rb_file_expand_path_internal(VALUE fname
 	    b = ++s;
 	    break;
 	  default:
-#ifdef __APPLE__
+#if 0
 	    {
 		int n = ignored_char_p(s, fend, enc);
 		if (n) {
