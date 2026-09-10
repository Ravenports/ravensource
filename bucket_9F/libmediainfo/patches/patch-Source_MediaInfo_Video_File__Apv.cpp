--- Source/MediaInfo/Video/File_Apv.cpp.orig	2026-09-10 01:19:07 UTC
+++ Source/MediaInfo/Video/File_Apv.cpp
@@ -502,8 +502,8 @@ void File_Apv::tile_info(FrameInfo& fi)
         Trusted_IsNot("Tile width or height is too small");
         return;
     }
-    int32u FrameWidthInMbsY = static_cast<int32u>(ceil(fi.frame_width / 16));
-    int32u FrameHeightInMbsY = static_cast<int32u>(ceil(fi.frame_height / 16));
+    int32u FrameWidthInMbsY = static_cast<int32u>(ceil(static_cast<double>(fi.frame_width) / 16));
+    int32u FrameHeightInMbsY = static_cast<int32u>(ceil(static_cast<double>(fi.frame_height) / 16));
     int32u tileCols = 0;
     int32u tileRows = 0;
     // Calculate number of columns
