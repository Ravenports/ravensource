--- cmake/modules/FindLua.cmake.orig	2026-07-08 19:27:06 UTC
+++ cmake/modules/FindLua.cmake
@@ -315,7 +315,7 @@ if (Lua_VERSION)
 endif ()
 
 find_library(LUA_LIBRARY
-  NAMES ${_lua_library_names} lua
+  NAMES ${_lua_library_names} lua-5.2
   NAMES_PER_DIR
   HINTS
     ${LUA_HINTS}
