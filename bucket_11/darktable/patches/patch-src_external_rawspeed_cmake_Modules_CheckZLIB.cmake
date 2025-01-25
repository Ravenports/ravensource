--- src/external/rawspeed/cmake/Modules/CheckZLIB.cmake.orig	2024-12-13 20:15:16 UTC
+++ src/external/rawspeed/cmake/Modules/CheckZLIB.cmake
@@ -47,7 +47,7 @@ endif()
 CHECK_PROTOTYPE_DEFINITION(zError
  "const char* zError(int zErrorCode)"
  "NULL"
- "zlib.h"
+ "stddef.h;zlib.h"
  HAVE_ZLIB_ZERROR_PROTOTYPE)
 if(NOT HAVE_ZLIB_ZERROR_PROTOTYPE)
   message(SEND_ERROR "Found unexpected prototype for zError() in <zlib.h>")
