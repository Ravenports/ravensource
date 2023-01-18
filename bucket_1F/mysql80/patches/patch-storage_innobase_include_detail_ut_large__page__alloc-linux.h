--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2022-12-16 15:34:44 UTC
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -34,6 +34,10 @@ this program; if not, write to the Free
 #include <sys/mman.h>
 #include <sys/types.h>
 
+#ifndef MAP_HUGETLB
+#define MAP_HUGETLB 0
+#endif
+
 #include "mysqld_error.h"
 #include "storage/innobase/include/detail/ut/helper.h"
 #include "storage/innobase/include/ut0log.h"
