--- src/core/CLucene/queryParser/legacy/Lexer.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/queryParser/legacy/Lexer.cpp
@@ -117,7 +117,7 @@ bool Lexer::GetNextToken(QueryToken* tok
       if( _istspace(ch)!=0 ) {
          continue;
       }
-      TCHAR buf[2] = {ch,'\0'};
+      TCHAR buf[2] = {TCHAR(ch),'\0'};
       switch(ch) {
          case '+':
             token->set(buf, QueryToken::PLUS);
