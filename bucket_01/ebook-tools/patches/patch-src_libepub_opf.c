--- src/libepub/opf.c.orig	2012-09-04 16:32:32.000000000 +0200
+++ src/libepub/opf.c	2024-08-15 22:53:59.711981000 +0200
@@ -394,6 +394,10 @@
      
       } else if (xmlTextReaderNodeType(reader) == 15) {
         if (item) {
+          if (! item->label) {
+            _epub_print_debug(opf->epub, DEBUG_WARNING, 
+                              "- missing navlabel for nav point element");
+          }
           _epub_print_debug(opf->epub, DEBUG_INFO, 
                             "adding nav point item->%s %s (d:%d,p:%d)", 
                             item->id, item->src, item->depth, item->playOrder);
