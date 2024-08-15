--- src/libepub/epub.c.orig	2024-08-15 22:47:17.465944000 +0200
+++ src/libepub/epub.c	2024-08-15 22:48:36.150292000 +0200
@@ -469,8 +469,9 @@
   case TITERATOR_NAVMAP:
   case TITERATOR_PAGES:
     ti = GetNodeData(curr);
-    tit->cache.label = 
-      (char *)_opf_label_get_by_doc_lang(tit->epub->opf, ti->label);
+    if (ti->label)
+      tit->cache.label =
+        (char *)_opf_label_get_by_doc_lang(tit->epub->opf, ti->label);
 
     if (! tit->cache.label)
       tit->cache.label = (char *)ti->id;
