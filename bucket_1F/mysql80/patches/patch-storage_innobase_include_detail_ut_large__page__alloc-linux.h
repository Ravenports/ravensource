--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2021-09-28 11:46:34 UTC
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -34,6 +34,10 @@ this program; if not, write to the Free
 #include <sys/mman.h>
 #include <sys/types.h>
 
+#ifndef MAP_HUGETLB
+#define MAP_HUGETLB 0
+#endif
+
 #include "storage/innobase/include/detail/ut/helper.h"
 
 extern const size_t large_page_default_size;
