--- svtools/source/svrtf/parrtf.cxx.orig	2021-05-19 18:12:30 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -50,6 +50,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
