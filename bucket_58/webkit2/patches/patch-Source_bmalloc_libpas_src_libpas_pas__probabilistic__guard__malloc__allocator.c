--- Source/bmalloc/libpas/src/libpas/pas_probabilistic_guard_malloc_allocator.c.orig	2023-02-20 09:22:22 UTC
+++ Source/bmalloc/libpas/src/libpas/pas_probabilistic_guard_malloc_allocator.c
@@ -114,11 +114,13 @@ pas_allocation_result pas_probabilistic_
      * ensure physical addresses are released
      * TODO: investigate using MADV_FREE_REUSABLE instead
      */
+    /* Linux 4.5, Ravenports uses 4.4
     int madvise_res = madvise((void *) upper_guard_page, page_size, MADV_FREE);
     PAS_ASSERT(!madvise_res);
 
     madvise_res = madvise((void *) lower_guard_page, page_size, MADV_FREE);
     PAS_ASSERT(!madvise_res);
+    */
 
     /*
      * the key is the location where the user's starting memory address is located.
@@ -180,8 +182,10 @@ void pas_probabilistic_guard_malloc_deal
 
     // ensure physical addresses are released
     // TODO: investigate using MADV_FREE_REUSABLE instead
+    /* Requires linux 4.5
     int madvise_res = madvise((void *) value->start_of_data_pages, value->size_of_data_pages, MADV_FREE);
     PAS_ASSERT(!madvise_res);
+    */
 
     bool removed = pas_ptr_hash_map_remove(&pas_pgm_hash_map, key, NULL, &pas_large_utility_free_heap_allocation_config);
     PAS_ASSERT(removed);
