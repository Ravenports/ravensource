--- src/p_lx_exc.cpp.orig	2025-05-06 10:19:16 UTC
+++ src/p_lx_exc.cpp
@@ -371,7 +371,7 @@ PackLinuxI386::buildLinuxLoader(
             (res->lit_pos_bits << 8) |
             (res->pos_bits << 16);
         if (bele->isBE()) // big endian - bswap32
-            properties = bswap32(properties);
+            properties = upx_bswap32(properties);
         linker->defineSymbol("lzma_properties", properties);
 
         // These lengths assume only one block (typ. 524288 bytes: 0.5 MiB).
