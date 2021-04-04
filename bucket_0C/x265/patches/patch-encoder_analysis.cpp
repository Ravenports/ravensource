--- encoder/analysis.cpp.orig	2021-03-16 12:53:00 UTC
+++ encoder/analysis.cpp
@@ -3739,7 +3739,7 @@ void Analysis::normFactor(const pixel* s
 
     // 2. Calculate ac component
     uint64_t z_k = 0;
-    int block = (int)(((log(blockSize) / log(2)) - 2) + 0.5);
+    int block = (int)(((std::log(blockSize) / std::log(2)) - 2) + 0.5);
     primitives.cu[block].normFact(src, blockSize, shift, &z_k);
 
     // Remove the DC part
