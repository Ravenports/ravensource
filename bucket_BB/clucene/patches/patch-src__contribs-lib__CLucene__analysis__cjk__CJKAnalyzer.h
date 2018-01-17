--- src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.h.orig	2011-03-17 00:21:07 UTC
+++ src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.h
@@ -39,7 +39,7 @@ private:
      * character buffer, store the characters which are used to compose <br>
      * the returned Token
      */
-    TCHAR buffer[LUCENE_MAX_WORD_LEN];
+    TCHAR buffer[LUCENE_MAX_WORD_LEN+1];
 
     /**
      * I/O buffer, used to store the content of the input(one of the <br>
