--- src/common/classes/alloc.h.orig	2019-06-17 15:15:52 UTC
+++ src/common/classes/alloc.h
@@ -92,7 +92,7 @@ namespace Firebird {
 const int MAX_TREE_DEPTH = 4;
 
 // Alignment for all memory blocks. Sizes of memory blocks in headers are measured in this units
-const size_t ALLOC_ALIGNMENT = FB_ALIGNMENT;
+#define ALLOC_ALIGNMENT 16
 
 static inline size_t MEM_ALIGN(size_t value)
 {
