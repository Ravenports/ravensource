--- encoder/analysis.cpp.orig	2026-04-19 06:29:17 UTC
+++ encoder/analysis.cpp
@@ -4421,7 +4421,7 @@ void Analysis::normFactor(const pixel* s
 
     // 2. Calculate ac component
     uint64_t z_k = 0;
-    int block = (int)(((log(blockSize) / log(2)) - 2) + 0.5);
+    int block = (int)(((std::log(blockSize) / std::log(2)) - 2) + 0.5);
     primitives.cu[block].normFact(src, blockSize, shift, &z_k);
 
     // Remove the DC part
