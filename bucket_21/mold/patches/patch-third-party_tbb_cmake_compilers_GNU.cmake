--- third-party/tbb/cmake/compilers/GNU.cmake.orig	2023-09-24 03:28:19 UTC
+++ third-party/tbb/cmake/compilers/GNU.cmake
@@ -40,9 +40,6 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(AMD
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<AND:$<NOT:$<CXX_COMPILER_ID:Intel>>,$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},11.0>>>:-mwaitpkg>)
 endif()
 
-if (NOT MINGW)
-    set(TBB_COMMON_LINK_LIBS dl)
-endif()
 
 # Ignore -Werror set through add_compile_options() or added to CMAKE_CXX_FLAGS if TBB_STRICT is disabled.
 if (NOT TBB_STRICT AND COMMAND tbb_remove_compile_flag)
