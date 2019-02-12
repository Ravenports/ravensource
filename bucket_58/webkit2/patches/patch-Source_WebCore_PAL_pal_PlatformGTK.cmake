--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2019-02-08 16:17:03 UTC
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -20,6 +20,13 @@ list(APPEND PAL_SOURCES
     unix/LoggingUnix.cpp
 )
 
+list(APPEND PAL_INCLUDE_DIRECTORIES
+    ${LIBGCRYPT_INCLUDE_DIRS}
+)
+list(APPEND PAL_LIBRARIES
+    ${LIBGCRYPT_LIBRARIES}
+)
+
 if (ENABLE_SUBTLE_CRYPTO)
     list(APPEND PAL_PUBLIC_HEADERS
         crypto/tasn1/Utilities.h
