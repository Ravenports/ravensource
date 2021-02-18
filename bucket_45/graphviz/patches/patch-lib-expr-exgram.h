--- lib/expr/exgram.h.orig	2021-02-13 17:02:13 UTC
+++ lib/expr/exgram.h
@@ -22,7 +22,7 @@ extern "C" {
  * sometimes free stuff can cost a lot
  */
 
-#if !defined(_EXGRAM_H) && ( defined(MINTOKEN) || defined(YYTOKENTYPE) )
+#if !defined(_EXGRAM_H)
 #define _EXGRAM_H
 
 #if !defined(_EXPARSE_H)
