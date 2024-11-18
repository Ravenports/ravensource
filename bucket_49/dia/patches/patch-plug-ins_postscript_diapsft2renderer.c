--- plug-ins/postscript/diapsft2renderer.c.orig	2014-08-24 15:46:01 UTC
+++ plug-ins/postscript/diapsft2renderer.c
@@ -61,16 +61,16 @@ void draw_bezier_outline(DiaPsRenderer *
 			 double pos_y
 			 );
 /* Countour traveling functions */
-static int paps_move_to( FT_Vector* to,
+static int paps_move_to( const FT_Vector* to,
 			 void *user_data);
-static int paps_line_to( FT_Vector*  to,
+static int paps_line_to( const FT_Vector*  to,
 			 void *user_data);
-static int paps_conic_to( FT_Vector*  control,
-			  FT_Vector*  to,
+static int paps_conic_to( const FT_Vector*  control,
+			  const FT_Vector*  to,
 			  void *user_data);
-static int paps_cubic_to( FT_Vector*  control1,
-			  FT_Vector*  control2,
-			  FT_Vector*  to,
+static int paps_cubic_to( const FT_Vector*  control1,
+			  const FT_Vector*  control2,
+			  const FT_Vector*  to,
 			  void *user_data);
 
 static void dia_ps_ft2_renderer_class_init (DiaPsFt2RendererClass *klass);
@@ -111,7 +111,7 @@ set_font(DiaRenderer *self, DiaFont *fon
 /*======================================================================
   outline traversing functions.
   ----------------------------------------------------------------------*/
-static int paps_move_to( FT_Vector* to,
+static int paps_move_to( const FT_Vector* to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -121,7 +121,7 @@ static int paps_move_to( FT_Vector* to,
   return 0;
 }
 
-static int paps_line_to( FT_Vector*  to,
+static int paps_line_to( const FT_Vector*  to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -131,8 +131,8 @@ static int paps_line_to( FT_Vector*  to,
   return 0;
 }
 
-static int paps_conic_to( FT_Vector*  control,
-			  FT_Vector*  to,
+static int paps_conic_to( const FT_Vector*  control,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -144,9 +144,9 @@ static int paps_conic_to( FT_Vector*  co
   return 0;
 }
 
-static int paps_cubic_to( FT_Vector*  control1,
-			  FT_Vector*  control2,
-			  FT_Vector*  to,
+static int paps_cubic_to( const FT_Vector*  control1,
+			  const FT_Vector*  control2,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
