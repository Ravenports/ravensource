--- prog/check_funs.cpp.orig	2011-07-04 09:17:27 UTC
+++ prog/check_funs.cpp
@@ -647,7 +647,7 @@ static void print_truncate(FILE * out, c
     }
   }
   if (i == width-1) {
-    if (word == '\0')
+    if (*word == '\0')
       put(out,' ');
     else if (word[len] == '\0')
       put(out, word, len);
