--- build/cmake/aom_optimization.cmake.orig	2019-12-11 23:49:30 UTC
+++ build/cmake/aom_optimization.cmake
@@ -83,7 +83,7 @@ function(get_asm_obj_format out_format)
   if("${AOM_TARGET_CPU}" STREQUAL "x86_64")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       set(objformat "macho64")
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
+    elseif("${AOM_TARGET_SYSTEM}" MATCHES "Linux|FreeBSD|DragonFly")
       set(objformat "elf64")
     elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS"
            OR "${AOM_TARGET_SYSTEM}" STREQUAL "Windows")
