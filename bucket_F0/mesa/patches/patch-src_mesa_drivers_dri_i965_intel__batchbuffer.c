--- src/mesa/drivers/dri/i965/intel_batchbuffer.c.orig	2019-10-24 16:13:04 UTC
+++ src/mesa/drivers/dri/i965/intel_batchbuffer.c
@@ -67,7 +67,7 @@ dump_validation_list(struct intel_batchb
       uint64_t flags = batch->validation_list[i].flags;
       assert(batch->validation_list[i].handle ==
              batch->exec_bos[i]->gem_handle);
-      fprintf(stderr, "[%2d]: %2d %-14s %p %s%-7s @ 0x%016llx%s (%"PRIu64"B)\n",
+      fprintf(stderr, "[%2d]: %2d %-14s %p %s%-7s @ 0x%016lx%s (%"PRIu64"B)\n",
               i,
               batch->validation_list[i].handle,
               batch->exec_bos[i]->name,
@@ -721,7 +721,7 @@ execbuffer(int fd,
 
       /* Update brw_bo::gtt_offset */
       if (batch->validation_list[i].offset != bo->gtt_offset) {
-         DBG("BO %d migrated: 0x%" PRIx64 " -> 0x%llx\n",
+         DBG("BO %d migrated: 0x%" PRIx64 " -> 0x%lx\n",
              bo->gem_handle, bo->gtt_offset,
              batch->validation_list[i].offset);
          assert(!(bo->kflags & EXEC_OBJECT_PINNED));
