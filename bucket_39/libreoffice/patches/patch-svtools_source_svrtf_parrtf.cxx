--- svtools/source/svrtf/parrtf.cxx.orig	2020-12-09 18:56:14 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -50,6 +50,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
