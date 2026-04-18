--- Source/MediaInfo/Image/File_Jpeg.h.orig	2026-04-18 14:43:08 UTC
+++ Source/MediaInfo/Image/File_Jpeg.h
@@ -20,6 +20,10 @@
 #include <memory>
 //---------------------------------------------------------------------------
 
+#ifdef SEC
+#undef SEC
+#endif
+
 namespace MediaInfoLib
 {
 
