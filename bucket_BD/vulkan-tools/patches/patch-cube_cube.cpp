--- cube/cube.cpp.orig	2026-08-28 03:05:46 UTC
+++ cube/cube.cpp
@@ -4153,6 +4153,7 @@ int WINAPI WinMain(HINSTANCE hInstance,
 }
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || \
+    defined(__DragonFly__) || \
     defined(__Fuchsia__)
 
 template <WsiPlatform WSI_PLATFORM>
