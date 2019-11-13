--- lib/expr/exgram.h.orig	2018-07-24 18:21:09 UTC
+++ lib/expr/exgram.h
@@ -23,7 +23,7 @@ extern "C" {
  * sometimes free stuff can cost a lot
  */
 
-#if !defined(_EXGRAM_H) && ( defined(MINTOKEN) || defined(YYTOKENTYPE) )
+#if !defined(_EXGRAM_H)
 #define _EXGRAM_H
 
 #if !defined(_EXPARSE_H)
