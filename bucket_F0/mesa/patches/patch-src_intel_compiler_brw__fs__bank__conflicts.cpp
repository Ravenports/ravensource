--- src/intel/compiler/brw_fs_bank_conflicts.cpp.orig	2025-01-22 18:12:23 UTC
+++ src/intel/compiler/brw_fs_bank_conflicts.cpp
@@ -309,8 +309,13 @@ namespace {
          const unsigned align = MAX2(sizeof(void *), __alignof__(vector_type));
          const unsigned size = DIV_ROUND_UP(n, vector_width) * sizeof(vector_type);
          void *p;
+#ifdef __sun
+	p = memalign(align, size);
+	if (p == NULL) return NULL;
+#else
          if (posix_memalign(&p, align, size))
             return NULL;
+#endif
          memset(p, 0, size);
          return reinterpret_cast<vector_type *>(p);
       }
@@ -716,7 +721,7 @@ namespace {
                    const weight_vector_type &conflicts)
    {
       const unsigned m = DIV_ROUND_UP(conflicts.size, vector_width);
-      vector_type s_p = {}, s_n = {};
+      vector_type s_p = {0}, s_n = {0};
 
       for (unsigned r = 0; r < m; r++) {
          s_p = adds(s_p, mask(bank_mask_p.v[r], conflicts.v[r]));
