--- frmts/jpeg2000/jpeg2000_vsil_io.cpp.orig	2020-07-07 11:46:27 UTC
+++ frmts/jpeg2000/jpeg2000_vsil_io.cpp
@@ -94,13 +94,13 @@ typedef struct {
 * File stream object.
 \******************************************************************************/
 
-static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, int cnt)
+static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, unsigned cnt)
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
     return static_cast<int>(VSIFReadL(buf, 1, cnt, fileobj->fp));
 }
 
-static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, int cnt)
+static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, unsigned cnt)
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
     return static_cast<int>(VSIFWriteL(buf, 1, cnt, fileobj->fp));
