--- C/hashes/hash.h.orig	2024-10-17 08:03:40 UTC
+++ C/hashes/hash.h
@@ -42,6 +42,11 @@
 
 #include "../7zTypes.h"
 
+#ifdef __NetBSD__
+#include <stdint.h>
+#define _UINT64_T_DECLARED
+#endif
+
 #ifndef _UINT32_T_DECLARED
 typedef UInt32 uint32_t;
 #define _UINT32_T_DECLARED
