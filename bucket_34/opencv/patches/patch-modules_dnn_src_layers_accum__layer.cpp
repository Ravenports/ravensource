--- modules/dnn/src/layers/accum_layer.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/layers/accum_layer.cpp
@@ -64,8 +64,8 @@ public:
             }
             outShape.push_back(totalchannels);
 
-            int out_h = divisor ? static_cast<int>(ceil(maxheight / divisor) * divisor) : top_height;
-            int out_w = divisor ? static_cast<int>(ceil(maxwidth / divisor) * divisor) : top_width;
+            int out_h = divisor ? static_cast<int>(ceil(static_cast<double>(maxheight) / divisor) * divisor) : top_height;
+            int out_w = divisor ? static_cast<int>(ceil(static_cast<double>(maxwidth) / divisor) * divisor) : top_width;
 
             // Layer can specify custom top size which is larger than default
             if (out_h <= maxheight || out_w <= maxwidth)
