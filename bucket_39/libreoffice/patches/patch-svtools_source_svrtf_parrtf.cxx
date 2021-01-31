--- svtools/source/svrtf/parrtf.cxx.orig	2021-01-27 19:33:49 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -50,6 +50,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
