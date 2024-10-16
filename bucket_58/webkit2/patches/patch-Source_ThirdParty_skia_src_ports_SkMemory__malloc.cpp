--- Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp.orig	2024-08-19 06:28:38 UTC
+++ Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp
@@ -16,7 +16,9 @@
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
 #elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+# if !defined(__DragonFly__)
 #include <malloc.h>
+# endif
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
 #endif
