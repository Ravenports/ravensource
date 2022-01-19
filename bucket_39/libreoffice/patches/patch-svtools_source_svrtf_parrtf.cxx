--- svtools/source/svrtf/parrtf.cxx.orig	2022-01-12 19:09:02 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -52,6 +52,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
