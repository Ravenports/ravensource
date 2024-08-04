--- src/p_vmlinz.cpp.orig	2024-05-09 10:03:12 UTC
+++ src/p_vmlinz.cpp
@@ -596,7 +596,7 @@ void PackBvmlinuzI386::pack(OutputFile *
             (res->lit_pos_bits << 8) |
             (res->pos_bits << 16);
         if (bele->isBE()) // big endian - bswap32
-            properties = bswap32(properties);
+            properties = upx_bswap32(properties);
         linker->defineSymbol("lzma_properties", properties);
         // -2 for properties
         if (linker->findSymbol("lzma_c_len", false)) {
