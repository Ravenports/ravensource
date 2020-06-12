--- svtools/source/svrtf/parrtf.cxx.orig	2020-05-13 11:19:20 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -49,6 +49,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
