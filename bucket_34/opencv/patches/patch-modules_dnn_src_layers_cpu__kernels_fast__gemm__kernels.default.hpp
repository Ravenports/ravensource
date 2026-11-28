--- modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.default.hpp.orig	2026-11-05 11:18:05 UTC
+++ modules/dnn/src/layers/cpu_kernels/fast_gemm_kernels.default.hpp
@@ -227,7 +227,7 @@ void fastGemmKernel(size_t M, size_t N,
     size_t total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         size_t start = r.start;
         size_t end = r.end;
@@ -293,7 +293,7 @@ void fastGemmKernel(size_t M, size_t N,
     size_t total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size)); // TODO: use AutoBuffer
         const char *packed_b_ = packed_B;
         size_t start = r.start;
         size_t end = r.end;
@@ -361,7 +361,7 @@ void fastGemmBatchKernel(size_t batch, c
     size_t total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         char* packed_b = packed_a + KC * MC * esz;
         size_t start = r.start;
         size_t end = r.end;
@@ -435,7 +435,7 @@ void fastGemmBatchKernel(size_t batch, c
     size_t total_tiles = m_tiles * n_tiles;
 
     auto fn = [&](const Range &r) {
-        char* packed_a = (char*)(use_stackbuff ? alloca(buff_size) : malloc(buff_size));
+        char* packed_a = (char*)(use_stackbuff ? __builtin_alloca(buff_size) : malloc(buff_size));
         const char *packed_b = packed_B;
         size_t start = r.start;
         size_t end = r.end;
