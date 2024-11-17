--- tkZinc.c.orig	2020-11-25 19:23:17 UTC
+++ tkZinc.c
@@ -8999,11 +8999,11 @@ InitZinc(Tcl_Interp *interp) {
   ZnTesselator.tess = gluNewTess();
   ZnTesselator.combine_list = NULL;
         ZnTesselator.combine_length = 0;
-  gluTessCallback(ZnTesselator.tess, GLU_TESS_BEGIN_DATA, ZnTessBegin);
-  gluTessCallback(ZnTesselator.tess, GLU_TESS_VERTEX_DATA, ZnTessVertex);
-  gluTessCallback(ZnTesselator.tess, GLU_TESS_END_DATA, ZnTessEnd);
-  gluTessCallback(ZnTesselator.tess, GLU_TESS_COMBINE_DATA, ZnTessCombine);
-  gluTessCallback(ZnTesselator.tess, GLU_TESS_ERROR_DATA, ZnTessError);
+  gluTessCallback(ZnTesselator.tess, GLU_TESS_BEGIN_DATA, (_GLUfuncptr)ZnTessBegin);
+  gluTessCallback(ZnTesselator.tess, GLU_TESS_VERTEX_DATA, (_GLUfuncptr)ZnTessVertex);
+  gluTessCallback(ZnTesselator.tess, GLU_TESS_END_DATA, (_GLUfuncptr)ZnTessEnd);
+  gluTessCallback(ZnTesselator.tess, GLU_TESS_COMBINE_DATA, (_GLUfuncptr)ZnTessCombine);
+  gluTessCallback(ZnTesselator.tess, GLU_TESS_ERROR_DATA, (_GLUfuncptr)ZnTessError);
   gluTessNormal(ZnTesselator.tess, 0.0, 0.0, -1.0);
 
   /*
