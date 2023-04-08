--- svtools/source/svrtf/parrtf.cxx.orig	2023-03-24 16:53:38 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -51,6 +51,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
