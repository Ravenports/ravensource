--- src/ui/widget/canvas/pixelstreamer.cpp.orig	2023-03-26 17:06:46 UTC
+++ src/ui/widget/canvas/pixelstreamer.cpp
@@ -99,7 +99,7 @@ public:
         // Calculate image properties required by cairo.
         int stride = cairo_format_stride_for_width(CAIRO_FORMAT_ARGB32, dimensions.x());
         int size = stride * dimensions.y();
-        int sizeup = Util::roundup(size, 64);
+        int sizeup = Util::inkscape_roundup(size, 64);
         assert(sizeup < bufsize);
 
         // Attempt to advance buffers in states 3 or 4 towards 5, if allowed.
