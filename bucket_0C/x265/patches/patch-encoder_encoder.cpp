$NetBSD: patch-encoder_encoder.cpp,v 1.3 2018/05/25 14:42:07 jperkin Exp $

Fix error: call of overloaded 'pow(int, int)' is ambiguous

--- encoder/encoder.cpp.orig	2024-11-22 12:07:34 UTC
+++ encoder/encoder.cpp
@@ -118,6 +118,7 @@ VideoSignalTypePresets vstPresets[] =
 static const char* defaultAnalysisFileName = "x265_analysis.dat";
 
 using namespace X265_NS;
+using std::pow;
 
 Encoder::Encoder()
 {
