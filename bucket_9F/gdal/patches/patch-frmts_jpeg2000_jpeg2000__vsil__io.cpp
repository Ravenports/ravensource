--- frmts/jpeg2000/jpeg2000_vsil_io.cpp.orig	2021-12-27 20:28:08 UTC
+++ frmts/jpeg2000/jpeg2000_vsil_io.cpp
@@ -94,28 +94,18 @@ typedef struct {
 * File stream object.
 \******************************************************************************/
 
-#if defined(PRIjas_seqent)
-// PRIjas_seqent macro is defined since Jasper 2.0.17
-static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, unsigned cnt)
-#else
-static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, int cnt)
-#endif
+// jasper 3.0
+static ssize_t JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, size_t cnt)
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
-    return static_cast<int>(VSIFReadL(buf, 1, cnt, fileobj->fp));
+    return static_cast<ssize_t>(VSIFReadL(buf, 1, cnt, fileobj->fp));
 }
 
-#if defined(JAS_INCLUDE_JP2_CODEC)
-// Jasper 2.0.21
-static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, const char *buf, unsigned int cnt)
-#elif defined(PRIjas_seqent)
-static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, unsigned int cnt)
-#else
-static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, int cnt)
-#endif
+// Jasper 3.0
+static ssize_t JPEG2000_VSIL_write(jas_stream_obj_t *obj, const char *buf, size_t cnt)
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
-    return static_cast<int>(VSIFWriteL(buf, 1, cnt, fileobj->fp));
+    return static_cast<ssize_t>(VSIFWriteL(buf, 1, cnt, fileobj->fp));
 }
 
 static long JPEG2000_VSIL_seek(jas_stream_obj_t *obj, long offset, int origin)
