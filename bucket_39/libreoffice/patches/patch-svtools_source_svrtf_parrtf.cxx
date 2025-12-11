--- svtools/source/svrtf/parrtf.cxx.orig	2025-12-01 19:30:03 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -52,6 +52,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
