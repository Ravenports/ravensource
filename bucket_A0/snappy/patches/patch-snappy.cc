--- snappy.cc.orig	2021-05-04 22:53:34 UTC
+++ snappy.cc
@@ -1014,7 +1014,7 @@ void MemMove(ptrdiff_t dst, const void*
 }
 
 SNAPPY_ATTRIBUTE_ALWAYS_INLINE
-size_t AdvanceToNextTag(const uint8_t** ip_p, size_t* tag) {
+inline size_t AdvanceToNextTag(const uint8_t** ip_p, size_t* tag) {
   const uint8_t*& ip = *ip_p;
   // This section is crucial for the throughput of the decompression loop.
   // The latency of an iteration is fundamentally constrained by the
