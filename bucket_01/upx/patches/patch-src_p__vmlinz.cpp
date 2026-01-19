--- src/p_vmlinz.cpp.orig	2026-01-07 11:13:41 UTC
+++ src/p_vmlinz.cpp
@@ -599,7 +599,7 @@ void PackBvmlinuzI386::pack(OutputFile *
             (res->lit_pos_bits << 8) |
             (res->pos_bits << 16);
         if (bele->isBE()) // big endian - bswap32
-            properties = bswap32(properties);
+            properties = upx_bswap32(properties);
         linker->defineSymbol("lzma_properties", properties);
         // -2 for properties
         if (linker->findSymbol("lzma_c_len", false)) {
