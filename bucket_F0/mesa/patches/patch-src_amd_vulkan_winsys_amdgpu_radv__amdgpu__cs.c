- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2026-07-29 17:31:27 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -40,6 +40,10 @@
 /* Maximum allowed total number of submitted IBs. */
 #define RADV_MAX_IBS_PER_SUBMIT 192
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 struct radv_amdgpu_ib {
    struct radeon_winsys_bo *bo; /* NULL when not owned by the current CS object */
    uint64_t va;
