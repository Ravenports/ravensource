--- src/3rdparty/eigen/Eigen/src/Core/util/Memory.h.orig	2025-05-04 13:16:35 UTC
+++ src/3rdparty/eigen/Eigen/src/Core/util/Memory.h
@@ -585,11 +585,7 @@ template<typename T> EIGEN_DEVICE_FUNC T
 // you can overwrite Eigen's default behavior regarding alloca by defining EIGEN_ALLOCA
 // to the appropriate stack allocation function
 #if ! defined EIGEN_ALLOCA && ! defined EIGEN_GPU_COMPILE_PHASE
-  #if EIGEN_OS_LINUX || EIGEN_OS_MAC || (defined alloca)
-    #define EIGEN_ALLOCA alloca
-  #elif EIGEN_COMP_MSVC
-    #define EIGEN_ALLOCA _alloca
-  #endif
+    #define EIGEN_ALLOCA __builtin_alloca
 #endif
 
 // With clang -Oz -mthumb, alloca changes the stack pointer in a way that is
