--- src/mesa/drivers/dri/i965/intel_batchbuffer.c.orig	2020-03-09 20:36:38 UTC
+++ src/mesa/drivers/dri/i965/intel_batchbuffer.c
@@ -67,7 +67,11 @@ dump_validation_list(struct intel_batchb
       uint64_t flags = batch->validation_list[i].flags;
       assert(batch->validation_list[i].handle ==
              batch->exec_bos[i]->gem_handle);
+#ifdef __linux__
       fprintf(stderr, "[%2d]: %2d %-14s %p %s%-7s @ 0x%016llx%s (%"PRIu64"B)\n",
+#else
+      fprintf(stderr, "[%2d]: %2d %-14s %p %s%-7s @ 0x%016lx%s (%"PRIu64"B)\n",
+#endif
               i,
               batch->validation_list[i].handle,
               batch->exec_bos[i]->name,
@@ -721,7 +725,11 @@ execbuffer(int fd,
 
       /* Update brw_bo::gtt_offset */
       if (batch->validation_list[i].offset != bo->gtt_offset) {
+#ifdef __linux__
          DBG("BO %d migrated: 0x%" PRIx64 " -> 0x%llx\n",
+#else
+         DBG("BO %d migrated: 0x%" PRIx64 " -> 0x%lx\n",
+#endif
              bo->gem_handle, bo->gtt_offset,
              batch->validation_list[i].offset);
          assert(!(bo->kflags & EXEC_OBJECT_PINNED));
