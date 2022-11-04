--- Source/bmalloc/libpas/src/libpas/pas_probabilistic_guard_malloc_allocator.c.orig	2022-09-08 11:51:52 UTC
+++ Source/bmalloc/libpas/src/libpas/pas_probabilistic_guard_malloc_allocator.c
@@ -103,11 +103,13 @@ pas_allocation_result pas_probabilistic_
 
     // ensure physical addresses are released
     // TODO: investigate using MADV_FREE_REUSABLE instead
+    /* Linux 4.5, Ravenports uses 4.4
     int madvise_res = madvise((void *) upper_guard_page, page_size, MADV_FREE);
     PAS_ASSERT(!madvise_res);
 
     madvise_res = madvise((void *) lower_guard_page, page_size, MADV_FREE);
     PAS_ASSERT(!madvise_res);
+    */
 
     // the key is the location where the user's starting memory address is located.
     // allocations are right aligned, so the end backs up to the upper guard page.
@@ -166,8 +168,10 @@ void pas_probabilistic_guard_malloc_deal
 
     // ensure physical addresses are released
     // TODO: investigate using MADV_FREE_REUSABLE instead
+    /* Requires linux 4.5
     int madvise_res = madvise((void *) value->start_of_data_pages, value->size_of_data_pages, MADV_FREE);
     PAS_ASSERT(!madvise_res);
+    */
 
     bool removed = pas_ptr_hash_map_remove(&pas_pgm_hash_map, key, NULL, &pas_large_utility_free_heap_allocation_config);
     PAS_ASSERT(removed);
