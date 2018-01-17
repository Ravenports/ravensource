--- src/core/CLucene/analysis/AnalysisHeader.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/analysis/AnalysisHeader.cpp
@@ -212,7 +212,7 @@ TCHAR* Token::toString() const{
     sb.append(_T(","));
     sb.appendInt( _endOffset );
 
-    if (!_tcscmp( _type, _T("word")) == 0 ){
+    if (_tcscmp( _type, _T("word")) != 0) {
       sb.append(_T(",type="));
       sb.append(_type);
     }
