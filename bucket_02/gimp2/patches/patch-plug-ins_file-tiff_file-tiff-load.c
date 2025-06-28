--- plug-ins/file-tiff/file-tiff-load.c.orig	2024-05-03 00:33:35 UTC
+++ plug-ins/file-tiff/file-tiff-load.c
@@ -1301,8 +1301,8 @@ load_image (GFile        *file,
 
       /* any resolution info in the file? */
       {
-        gfloat   xres = 72.0;
-        gfloat   yres = 72.0;
+        double   xres = 72.0;
+        double   yres = 72.0;
         gushort  read_unit;
         GimpUnit unit = GIMP_UNIT_PIXEL; /* invalid unit */
 
