--- operations/external/exr-load.cpp.orig	2020-12-20 12:16:48 UTC
+++ operations/external/exr-load.cpp
@@ -29,9 +29,7 @@ property_file_path (path, "File", "")
 #define GEGL_OP_NAME exr_load
 #define GEGL_OP_C_FILE       "exr-load.cpp"
 
-extern "C" {
 #include "gegl-op.h"
-}
 
 #include <ImfInputFile.h>
 #include <ImfChannelList.h>
