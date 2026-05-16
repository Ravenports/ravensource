--- src/3rdparty/eigen/Eigen/src/Core/util/Memory.h.orig	2026-05-08 03:28:44 UTC
+++ src/3rdparty/eigen/Eigen/src/Core/util/Memory.h
@@ -646,11 +646,7 @@ EIGEN_DEVICE_FUNC T* smart_move(T* start
 // you can overwrite Eigen's default behavior regarding alloca by defining EIGEN_ALLOCA
 // to the appropriate stack allocation function
 #if !defined EIGEN_ALLOCA && !defined EIGEN_GPU_COMPILE_PHASE
-#if EIGEN_OS_LINUX || EIGEN_OS_MAC || (defined alloca)
-#define EIGEN_ALLOCA alloca
-#elif EIGEN_COMP_MSVC
-#define EIGEN_ALLOCA _alloca
-#endif
+#define EIGEN_ALLOCA _builtin_alloca
 #endif
 
 // With clang -Oz -mthumb, alloca changes the stack pointer in a way that is
