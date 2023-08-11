--- src/attributes.cpp.orig	2023-07-16 14:32:51 UTC
+++ src/attributes.cpp
@@ -142,7 +142,7 @@ static SPStyleProp const props[] = {
     /* SPPage */
     {SPAttr::PAGE_MARGIN, "margin"},
     {SPAttr::PAGE_BLEED, "bleed"},
-    {SPAttr::PAGE_SIZE, "page-size"},
+    {SPAttr::INKSCAPE_PAGE_SIZE, "page-size"},
     /* SPGrid */
     {SPAttr::ORIGINX, "originx"},
     {SPAttr::ORIGINY, "originy"},
