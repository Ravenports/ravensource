--- svtools/source/svrtf/parrtf.cxx.orig	2020-06-24 20:35:34 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -49,6 +49,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
