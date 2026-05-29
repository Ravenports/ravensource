--- lib/expr/exgram.h.orig	2026-05-23 18:42:32 UTC
+++ lib/expr/exgram.h
@@ -19,7 +19,7 @@ extern "C" {
  * with both yacc and bison
  */
 
-#if !defined(_EXGRAM_H) && ( defined(MINTOKEN) || defined(YYTOKENTYPE) )
+#if !defined(_EXGRAM_H)
 #define _EXGRAM_H
 
 #include <expr/exlib.h>
