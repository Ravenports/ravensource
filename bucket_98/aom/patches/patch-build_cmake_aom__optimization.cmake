Corrects feature detection for NASM 3.01

--- build/cmake/aom_optimization.cmake.orig	2025-09-05 22:10:37 UTC
+++ build/cmake/aom_optimization.cmake
@@ -213,7 +213,10 @@ endfunction()
 # the -Ox argument (multipass optimization).
 function(test_nasm)
   execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hf
-                  OUTPUT_VARIABLE nasm_helptext)
+                  OUTPUT_VARIABLE nasm_hf)
+  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hO
+                  OUTPUT_VARIABLE nasm_ho)
+  set(nasm_helptext "${nasm_hf};${nasm_ho}")
 
   if(NOT "${nasm_helptext}" MATCHES "-Ox")
     message(
