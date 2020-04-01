--- file.c.orig	2020-03-31 12:15:56 UTC
+++ file.c
@@ -19,9 +19,6 @@
 #include <sys/cygwin.h>
 #include <wchar.h>
 #endif
-#ifdef __APPLE__
-#include <CoreFoundation/CFString.h>
-#endif
 
 #include "id.h"
 #include "internal.h"
@@ -242,7 +239,7 @@ rb_str_encode_ospath(VALUE path)
     return path;
 }
 
-#ifdef __APPLE__
+#if 0
 # define NORMALIZE_UTF8PATH 1
 static VALUE
 rb_str_append_normalized_ospath(VALUE str, const char *ptr, long len)
@@ -3680,7 +3677,7 @@ rb_file_expand_path_internal(VALUE fname
 	    b = ++s;
 	    break;
 	  default:
-#ifdef __APPLE__
+#if 0
 	    {
 		int n = ignored_char_p(s, fend, enc);
 		if (n) {
