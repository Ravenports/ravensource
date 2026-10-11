--- Source/MediaInfo/Image/File_Jpeg.h.orig	2026-10-11 21:31:25 UTC
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
 
