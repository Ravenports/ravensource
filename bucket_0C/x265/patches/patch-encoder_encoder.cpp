$NetBSD: patch-encoder_encoder.cpp,v 1.3 2018/05/25 14:42:07 jperkin Exp $

Fix error: call of overloaded 'pow(int, int)' is ambiguous

--- encoder/encoder.cpp.orig	2019-01-23 09:47:18 UTC
+++ encoder/encoder.cpp
@@ -83,6 +83,7 @@ DolbyVisionProfileSpec dovi[] =
 static const char* defaultAnalysisFileName = "x265_analysis.dat";
 
 using namespace X265_NS;
+using std::pow;
 
 Encoder::Encoder()
 {
