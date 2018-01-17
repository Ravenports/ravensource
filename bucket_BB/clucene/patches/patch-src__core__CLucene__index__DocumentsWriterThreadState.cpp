--- src/core/CLucene/index/DocumentsWriterThreadState.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/index/DocumentsWriterThreadState.cpp
@@ -994,7 +994,7 @@ void DocumentsWriter::ThreadState::Field
   const TCHAR* tokenText = token->termBuffer();
   const int32_t tokenTextLen = token->termLength();
 
-  int32_t code = 0;
+  uint32_t code = 0;
 
   // Compute hashcode
   int32_t downto = tokenTextLen;
@@ -1203,7 +1203,8 @@ void DocumentsWriter::ThreadState::Field
   const int32_t newMask = newSize-1;
 
   ValueArray<Posting*> newHash(newSize);
-  int32_t hashPos, code;
+  int32_t hashPos;
+  uint32_t code;
   const TCHAR* pos = NULL;
   const TCHAR* start = NULL;
   Posting* p0;
