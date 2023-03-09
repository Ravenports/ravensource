--- cmake/FindMsgpack.cmake.orig	2023-02-02 13:33:23 UTC
+++ cmake/FindMsgpack.cmake
@@ -30,7 +30,7 @@ if(MSVC)
   # The import library for the msgpack DLL has a different name
   list(APPEND MSGPACK_NAMES msgpackc_import)
 else()
-  list(APPEND MSGPACK_NAMES msgpackc msgpack)
+  list(APPEND MSGPACK_NAMES msgpackc msgpack msgpack-c)
 endif()
 
 find_library(MSGPACK_LIBRARY NAMES ${MSGPACK_NAMES}
