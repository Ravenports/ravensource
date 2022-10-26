- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2022-10-19 16:50:22 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -46,6 +46,10 @@
 
 enum { VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024 };
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 struct radv_amdgpu_ib {
    struct radeon_winsys_bo *bo;
    unsigned cdw;
