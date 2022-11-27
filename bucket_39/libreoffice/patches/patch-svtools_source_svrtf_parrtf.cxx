--- svtools/source/svrtf/parrtf.cxx.orig	2022-11-16 17:29:15 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -51,6 +51,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
