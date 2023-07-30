$NetBSD: patch-src_tokenise.c,v 1.2 2015/07/27 22:24:51 wiz Exp $

Fix C99 inline usage.

--- src/tokenise.c.orig	2011-11-05 11:40:53 UTC
+++ src/tokenise.c
@@ -154,9 +154,9 @@ ZDictionary* dictionary_cache(const ZUWo
 
 int cache = 1;
 
-inline ZUWord lookup_word(unsigned int*  word,
-			  int            wordlen,
-			  ZUWord         dct)
+ZUWord lookup_word(unsigned int*  word,
+		   int            wordlen,
+		   ZUWord         dct)
 {
   ZByte packed[12];
   int zscii_len;
