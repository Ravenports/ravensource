--- cmake/modules/FindLua.cmake.orig	2025-11-19 18:26:29 UTC
+++ cmake/modules/FindLua.cmake
@@ -179,7 +179,7 @@ if (LUA_VERSION_STRING)
 endif ()
 
 find_library(LUA_LIBRARY
-  NAMES ${_lua_library_names} lua
+  NAMES ${_lua_library_names} lua-5.2
   NAMES_PER_DIR
   HINTS
     ${LUA_HINTS}
