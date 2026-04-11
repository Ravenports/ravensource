--- modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.simd.hpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.simd.hpp
@@ -586,7 +586,7 @@ void fastGemmKernel(int M, int N, int K,
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         int start = r.start;
         int end = r.end;
@@ -674,7 +674,7 @@ void fastGemmKernel(int M, int N, int K,
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
         const char *packed_b_ = packed_B;
         int start = r.start;
         int end = r.end;
@@ -753,7 +753,7 @@ void fastGemmBatchKernel(size_t batch, c
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         int start = r.start;
         int end = r.end;
@@ -843,7 +843,7 @@ void fastGemmBatchKernel(size_t batch, c
     int total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         const char *packed_b = packed_B;
         int start = r.start;
         int end = r.end;
