--- Source/LibJXR/image/sys/strcodec.h.orig	2024-11-18 00:57:46 UTC
+++ Source/LibJXR/image/sys/strcodec.h
@@ -111,6 +111,8 @@ CT_ASSERT(sizeof(INTPTR_T) == sizeof(voi
 #define ALIGNUP(p, s) ((void*)(((UINTPTR_T)(p) + ((UINTPTR_T)(s) - 1)) & ~((UINTPTR_T)(s) - 1)))
 #define ALIGNDOWN(p, s) ((void*)((UINTPTR_T)(p) & ~((UINTPTR_T)(s) - 1)))
 
+U32 _byteswap_ulong(U32 bits);
+
 //================================================================
 // timer support
 //================================================================
