--- lib/expr/exgram.h.orig	2024-11-03 19:31:07 UTC
+++ lib/expr/exgram.h
@@ -19,7 +19,7 @@ extern "C" {
  * with both yacc and bison
  */
 
-#if !defined(_EXGRAM_H) && ( defined(MINTOKEN) || defined(YYTOKENTYPE) )
+#if !defined(_EXGRAM_H)
 #define _EXGRAM_H
 
 #include <cgraph/agxbuf.h>
