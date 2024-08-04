--- src/p_lx_exc.cpp.orig	2024-05-09 10:03:12 UTC
+++ src/p_lx_exc.cpp
@@ -380,7 +380,7 @@ PackLinuxI386::buildLinuxLoader(
             (res->lit_pos_bits << 8) |
             (res->pos_bits << 16);
         if (bele->isBE()) // big endian - bswap32
-            properties = bswap32(properties);
+            properties = upx_bswap32(properties);
         linker->defineSymbol("lzma_properties", properties);
 
         // These lengths assume only one block (typ. 524288 bytes: 0.5 MiB).
