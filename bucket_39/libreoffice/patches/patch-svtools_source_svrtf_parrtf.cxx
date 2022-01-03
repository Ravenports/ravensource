--- svtools/source/svrtf/parrtf.cxx.orig	2021-12-21 19:06:48 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -52,6 +52,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
