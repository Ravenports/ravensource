--- src/mesa/drivers/dri/i965/brw_bufmgr.c.orig	2020-03-18 21:24:19 UTC
+++ src/mesa/drivers/dri/i965/brw_bufmgr.c
@@ -74,6 +74,10 @@
 #define VG(x)
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* VALGRIND_FREELIKE_BLOCK unfortunately does not actually undo the earlier
  * VALGRIND_MALLOCLIKE_BLOCK but instead leaves vg convinced the memory is
  * leaked. All because it does not call VG(cli_free) from its
@@ -1699,8 +1703,12 @@ brw_bufmgr_init(struct gen_device_info *
       bufmgr->initial_kflags |= EXEC_OBJECT_SUPPORTS_48B_ADDRESS;
 
       /* Allocate VMA in userspace if we have softpin and full PPGTT. */
+#ifdef __DragonFly__
+      if (false) {
+#else
       if (gem_param(fd, I915_PARAM_HAS_EXEC_SOFTPIN) > 0 &&
           gem_param(fd, I915_PARAM_HAS_ALIASING_PPGTT) > 1) {
+#endif
          bufmgr->initial_kflags |= EXEC_OBJECT_PINNED;
 
          util_vma_heap_init(&bufmgr->vma_allocator[BRW_MEMZONE_LOW_4G],
