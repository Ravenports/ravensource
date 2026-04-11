--- modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.default.hpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.default.hpp
@@ -198,7 +198,7 @@ void fastGemmKernel(int M, int N, int K,
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         int start = r.start;
         int end = r.end;
@@ -264,7 +264,7 @@ void fastGemmKernel(int M, int N, int K,
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
         const char *packed_b_ = packed_B;
         int start = r.start;
         int end = r.end;
@@ -332,7 +332,7 @@ void fastGemmBatchKernel(size_t batch, c
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         int start = r.start;
         int end = r.end;
@@ -406,7 +406,7 @@ void fastGemmBatchKernel(size_t batch, c
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         const char *packed_b = packed_B;
         int start = r.start;
         int end = r.end;
