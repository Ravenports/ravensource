--- file.c.orig	2021-11-24 11:53:13 UTC
+++ file.c
@@ -19,9 +19,6 @@
 #include <sys/cygwin.h>
 #include <wchar.h>
 #endif
-#ifdef __APPLE__
-#include <CoreFoundation/CFString.h>
-#endif
 
 #include "id.h"
 #include "ruby/encoding.h"
@@ -243,7 +240,7 @@ rb_str_encode_ospath(VALUE path)
     return path;
 }
 
-#ifdef __APPLE__
+#if 0
 # define NORMALIZE_UTF8PATH 1
 static VALUE
 rb_str_append_normalized_ospath(VALUE str, const char *ptr, long len)
@@ -3708,7 +3705,7 @@ rb_file_expand_path_internal(VALUE fname
 	    b = ++s;
 	    break;
 	  default:
-#ifdef __APPLE__
+#if 0
 	    {
 		int n = ignored_char_p(s, fend, enc);
 		if (n) {
