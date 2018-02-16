--- glm/simd/platform.h.orig	2017-08-16 12:15:24 UTC
+++ glm/simd/platform.h
@@ -94,24 +94,14 @@
 
 // GCC defines
 #define GLM_COMPILER_GCC			0x02000000
-#define GLM_COMPILER_GCC44			0x020000B0
-#define GLM_COMPILER_GCC45			0x020000C0
 #define GLM_COMPILER_GCC46			0x020000D0
 #define GLM_COMPILER_GCC47			0x020000E0
 #define GLM_COMPILER_GCC48			0x020000F0
 #define GLM_COMPILER_GCC49			0x02000100
-#define GLM_COMPILER_GCC50			0x02000200
-#define GLM_COMPILER_GCC51			0x02000300
-#define GLM_COMPILER_GCC52			0x02000400
-#define GLM_COMPILER_GCC53			0x02000500
-#define GLM_COMPILER_GCC54			0x02000600
-#define GLM_COMPILER_GCC60			0x02000700
-#define GLM_COMPILER_GCC61			0x02000800
-#define GLM_COMPILER_GCC62			0x02000900
-#define GLM_COMPILER_GCC70			0x02000A00
-#define GLM_COMPILER_GCC71			0x02000B00
-#define GLM_COMPILER_GCC72			0x02000C00
-#define GLM_COMPILER_GCC80			0x02000D00
+#define GLM_COMPILER_GCC5			0x02000200
+#define GLM_COMPILER_GCC6			0x02000300
+#define GLM_COMPILER_GCC7			0x02000400
+#define GLM_COMPILER_GCC8			0x02000500
 
 // CUDA
 #define GLM_COMPILER_CUDA			0x10000000
@@ -245,14 +235,8 @@
 
 // G++
 #elif defined(__GNUC__) || defined(__MINGW32__)
-#	if (__GNUC__ == 4) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC42)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 3)
-#		define GLM_COMPILER (GLM_COMPILER_GCC43)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 4)
-#		define GLM_COMPILER (GLM_COMPILER_GCC44)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 5)
-#		define GLM_COMPILER (GLM_COMPILER_GCC45)
+#	if ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
+#		error "GLM requires GCC 4.7 or higher"
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
 #		define GLM_COMPILER (GLM_COMPILER_GCC46)
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 7)
@@ -261,32 +245,14 @@
 #		define GLM_COMPILER (GLM_COMPILER_GCC48)
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)
 #		define GLM_COMPILER (GLM_COMPILER_GCC49)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC50)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC51)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC52)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 3)
-#		define GLM_COMPILER (GLM_COMPILER_GCC53)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ >= 4)
-#		define GLM_COMPILER (GLM_COMPILER_GCC54)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC60)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC61)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ >= 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC62)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC70)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC71)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC72)
+#	elif (__GNUC__ == 5)
+#		define GLM_COMPILER (GLM_COMPILER_GCC5)
+#	elif (__GNUC__ == 6)
+#		define GLM_COMPILER (GLM_COMPILER_GCC6)
+#	elif (__GNUC__ == 7)
+#		define GLM_COMPILER (GLM_COMPILER_GCC7)
 #	elif (__GNUC__ >= 8)
-#		define GLM_COMPILER (GLM_COMPILER_GCC80)
-#	else
-#		define GLM_COMPILER (GLM_COMPILER_GCC)
+#		define GLM_COMPILER (GLM_COMPILER_GCC8)
 #	endif
 
 #else
