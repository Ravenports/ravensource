- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2024-05-08 13:28:59 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -48,6 +48,10 @@
 
 enum { VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024 };
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 struct radv_amdgpu_ib {
    struct radeon_winsys_bo *bo;
    unsigned cdw;
