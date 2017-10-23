--- src/hb-set-private.hh.orig	2017-10-22 20:57:33 UTC
+++ src/hb-set-private.hh
@@ -369,7 +369,7 @@ struct hb_set_t
       return *codepoint != INVALID;
     }
 
-    page_map_t map = {major (*codepoint), 0};
+    page_map_t map = {get_major (*codepoint), 0};
     unsigned int i;
     page_map.bfind (&map, &i);
     if (i < page_map.len)
@@ -441,7 +441,7 @@ struct hb_set_t
 
   page_t *page_for_insert (hb_codepoint_t g)
   {
-    page_map_t map = {major (g), pages.len};
+    page_map_t map = {get_major (g), pages.len};
     unsigned int i;
     if (!page_map.bfind (&map, &i))
     {
@@ -456,7 +456,7 @@ struct hb_set_t
   }
   page_t *page_for (hb_codepoint_t g)
   {
-    page_map_t key = {major (g)};
+    page_map_t key = {get_major (g)};
     const page_map_t *found = page_map.bsearch (&key);
     if (found)
       return &pages[found->index];
@@ -464,7 +464,7 @@ struct hb_set_t
   }
   const page_t *page_for (hb_codepoint_t g) const
   {
-    page_map_t key = {major (g)};
+    page_map_t key = {get_major (g)};
     const page_map_t *found = page_map.bsearch (&key);
     if (found)
       return &pages[found->index];
@@ -472,7 +472,7 @@ struct hb_set_t
   }
   page_t &page_at (unsigned int i) { return pages[page_map[i].index]; }
   const page_t &page_at (unsigned int i) const { return pages[page_map[i].index]; }
-  unsigned int major (hb_codepoint_t g) const { return g / PAGE_SIZE; }
+  unsigned int get_major (hb_codepoint_t g) const { return g / PAGE_SIZE; }
 };
 
 
