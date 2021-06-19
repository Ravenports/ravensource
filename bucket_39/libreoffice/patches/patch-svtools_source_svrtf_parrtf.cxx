--- svtools/source/svrtf/parrtf.cxx.orig	2021-06-04 14:36:10 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -50,6 +50,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
