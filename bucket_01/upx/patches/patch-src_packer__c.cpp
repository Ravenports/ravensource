--- src/packer_c.cpp.orig	2025-02-20 15:02:44 UTC
+++ src/packer_c.cpp
@@ -258,7 +258,7 @@ void Packer::defineDecompressorSymbols()
         upx_uint32_t properties = // lc, lp, pb, dummy
             (res->lit_context_bits << 0) | (res->lit_pos_bits << 8) | (res->pos_bits << 16);
         if (bele->isBE()) // big endian - bswap32
-            properties = bswap32(properties);
+            properties = upx_bswap32(properties);
 
         linker->defineSymbol("lzma_properties", properties);
         // len - 2 because of properties
