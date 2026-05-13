--- svtools/source/svrtf/parrtf.cxx.orig	2026-04-24 19:21:51 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -52,6 +52,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
