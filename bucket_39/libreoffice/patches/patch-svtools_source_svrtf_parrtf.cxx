--- svtools/source/svrtf/parrtf.cxx.orig	2024-07-10 15:12:43 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -52,6 +52,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
