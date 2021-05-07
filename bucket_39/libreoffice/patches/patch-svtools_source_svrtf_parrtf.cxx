--- svtools/source/svrtf/parrtf.cxx.orig	2021-04-28 16:17:45 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -50,6 +50,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
