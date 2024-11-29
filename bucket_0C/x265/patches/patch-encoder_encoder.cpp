$NetBSD: patch-encoder_encoder.cpp,v 1.3 2018/05/25 14:42:07 jperkin Exp $

Fix error: call of overloaded 'pow(int, int)' is ambiguous

--- encoder/encoder.cpp.orig	2024-09-13 13:02:55 UTC
+++ encoder/encoder.cpp
@@ -118,6 +118,7 @@ VideoSignalTypePresets vstPresets[] =
 static const char* defaultAnalysisFileName = "x265_analysis.dat";
 
 using namespace X265_NS;
+using std::pow;
 
 Encoder::Encoder()
 {
