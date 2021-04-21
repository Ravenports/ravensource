--- lib/expr/exgram.h.orig	2021-04-17 19:19:13 UTC
+++ lib/expr/exgram.h
@@ -20,7 +20,7 @@ extern "C" {
  * sometimes free stuff can cost a lot
  */
 
-#if !defined(_EXGRAM_H) && ( defined(MINTOKEN) || defined(YYTOKENTYPE) )
+#if !defined(_EXGRAM_H)
 #define _EXGRAM_H
 
 #if !defined(_EXPARSE_H)
