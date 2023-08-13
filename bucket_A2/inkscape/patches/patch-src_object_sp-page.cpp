--- src/object/sp-page.cpp.orig	2023-07-14 12:25:09 UTC
+++ src/object/sp-page.cpp
@@ -42,7 +42,7 @@ void SPPage::build(SPDocument *document,
     SPObject::build(document, repr);
 
     this->readAttr(SPAttr::INKSCAPE_LABEL);
-    this->readAttr(SPAttr::PAGE_SIZE);
+    this->readAttr(SPAttr::INKSCAPE_PAGE_SIZE);
     this->readAttr(SPAttr::X);
     this->readAttr(SPAttr::Y);
     this->readAttr(SPAttr::WIDTH);
@@ -85,7 +85,7 @@ void SPPage::set(SPAttr key, const gchar
         case SPAttr::PAGE_BLEED:
             this->bleed.readOrUnset(value);
             break;
-        case SPAttr::PAGE_SIZE:
+        case SPAttr::INKSCAPE_PAGE_SIZE:
             this->_size_label = value ? std::string(value) : "";
             break;
         default:
