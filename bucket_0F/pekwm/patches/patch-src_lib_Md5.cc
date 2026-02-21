--- src/lib/Md5.cc.orig	2026-01-03 06:49:57 UTC
+++ src/lib/Md5.cc
@@ -11,6 +11,10 @@ extern "C" {
 #include <stdio.h>
 }
 
+#if !defined(UINT32_MAX)
+#define UINT32_MAX      0xffffffffU  // Hidden on FreeBSD from c++
+#endif
+
 #define F(x, y, z) (z ^ (x & (y ^ z)))
 #define G(x, y, z) (y ^ (z & (x ^ y)))
 #define H(x, y, z) (x ^ y ^ z)
