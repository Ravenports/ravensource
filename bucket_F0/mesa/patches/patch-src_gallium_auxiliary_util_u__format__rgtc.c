--- src/gallium/auxiliary/util/u_format_rgtc.c.orig	2020-03-09 20:36:38 UTC
+++ src/gallium/auxiliary/util/u_format_rgtc.c
@@ -175,13 +175,13 @@ util_format_rgtc1_snorm_pack_rgba_float(
    for(y = 0; y < height; y += bh) {
       int8_t *dst = (int8_t *)dst_row;
       for(x = 0; x < width; x += bw) {
-         int8_t tmp[4][4];  /* [bh][bw][comps] */
+         signed char tmp[4][4];  /* [bh][bw][comps] */
          for(j = 0; j < bh; ++j) {
             for(i = 0; i < bw; ++i) {
-	       tmp[j][i] = float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4]);
+	       tmp[j][i] = (signed char)float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4]);
             }
          }
-         util_format_signed_encode_rgtc_ubyte(dst, tmp, 4, 4);
+         util_format_signed_encode_rgtc_ubyte((signed char *)dst, tmp, 4, 4);
          dst += bytes_per_block;
       }
       dst_row += dst_stride / sizeof(*dst_row);
@@ -194,14 +194,14 @@ util_format_rgtc1_snorm_unpack_rgba_floa
    unsigned x, y, i, j;
    int block_size = 8;
    for(y = 0; y < height; y += 4) {
-      const int8_t *src = (int8_t *)src_row;
+      const signed char *src = (signed char *)src_row;
       for(x = 0; x < width; x += 4) {
          for(j = 0; j < 4; ++j) {
             for(i = 0; i < 4; ++i) {
                float *dst = dst_row + (y + j)*dst_stride/sizeof(*dst_row) + (x + i)*4;
-               int8_t tmp_r;
+               signed char tmp_r;
                util_format_signed_fetch_texel_rgtc(0, src, i, j, &tmp_r, 1);
-               dst[0] = byte_to_float_tex(tmp_r);
+               dst[0] = byte_to_float_tex((int8_t)tmp_r);
                dst[1] = 0.0;
                dst[2] = 0.0;
                dst[3] = 1.0;
@@ -216,9 +216,9 @@ util_format_rgtc1_snorm_unpack_rgba_floa
 void
 util_format_rgtc1_snorm_fetch_rgba_float(float *dst, const uint8_t *src, unsigned i, unsigned j)
 {
-   int8_t tmp_r;
-   util_format_signed_fetch_texel_rgtc(0, (int8_t *)src, i, j, &tmp_r, 1);
-   dst[0] = byte_to_float_tex(tmp_r);
+   signed char tmp_r;
+   util_format_signed_fetch_texel_rgtc(0, (signed char *)src, i, j, &tmp_r, 1);
+   dst[0] = byte_to_float_tex((int8_t)tmp_r);
    dst[1] = 0.0;
    dst[2] = 0.0;
    dst[3] = 1.0;
@@ -268,16 +268,16 @@ util_format_rgtc2_unorm_pack_rgba_8unorm
    for(y = 0; y < height; y += bh) {
       uint8_t *dst = dst_row;
       for(x = 0; x < width; x += bw) {
-         uint8_t tmp_r[4][4];  /* [bh][bw] */
-         uint8_t tmp_g[4][4];  /* [bh][bw] */
+         unsigned char tmp_r[4][4];  /* [bh][bw] */
+         unsigned char tmp_g[4][4];  /* [bh][bw] */
          for(j = 0; j < bh; ++j) {
             for(i = 0; i < bw; ++i) {
-	       tmp_r[j][i] = src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4];
-	       tmp_g[j][i] = src_row[((y + j)*src_stride/sizeof(*src_row) + (x + i)*4) + 1];
+	       tmp_r[j][i] = (unsigned char)src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4];
+	       tmp_g[j][i] = (unsigned char)src_row[((y + j)*src_stride/sizeof(*src_row) + (x + i)*4) + 1];
             }
          }
-         util_format_unsigned_encode_rgtc_ubyte(dst, tmp_r, 4, 4);
-         util_format_unsigned_encode_rgtc_ubyte(dst + 8, tmp_g, 4, 4);
+         util_format_unsigned_encode_rgtc_ubyte((unsigned char *)dst, tmp_r, 4, 4);
+         util_format_unsigned_encode_rgtc_ubyte((unsigned char *)(dst + 8), tmp_g, 4, 4);
          dst += bytes_per_block;
       }
       dst_row += dst_stride / sizeof(*dst_row);
@@ -383,16 +383,16 @@ util_format_rgtc2_snorm_unpack_rgba_floa
    unsigned x, y, i, j;
    int block_size = 16;
    for(y = 0; y < height; y += 4) {
-      const int8_t *src = (int8_t *)src_row;
+      const signed char *src = (signed char *)src_row;
       for(x = 0; x < width; x += 4) {
          for(j = 0; j < 4; ++j) {
             for(i = 0; i < 4; ++i) {
                float *dst = dst_row + (y + j)*dst_stride/sizeof(*dst_row) + (x + i)*4;
-               int8_t tmp_r, tmp_g;
+               signed char tmp_r, tmp_g;
                util_format_signed_fetch_texel_rgtc(0, src, i, j, &tmp_r, 2);
                util_format_signed_fetch_texel_rgtc(0, src + 8, i, j, &tmp_g, 2);
-               dst[0] = byte_to_float_tex(tmp_r);
-               dst[1] = byte_to_float_tex(tmp_g);
+               dst[0] = byte_to_float_tex((int8_t)tmp_r);
+               dst[1] = byte_to_float_tex((int8_t)tmp_g);
                dst[2] = 0.0;
                dst[3] = 1.0;
             }
@@ -410,14 +410,14 @@ util_format_rxtc2_snorm_pack_rgba_float(
    unsigned x, y, i, j;
 
    for(y = 0; y < height; y += bh) {
-      int8_t *dst = (int8_t *)dst_row;
+      signed char *dst = (signed char *)dst_row;
       for(x = 0; x < width; x += bw) {
-         int8_t tmp_r[4][4];  /* [bh][bw][comps] */
-         int8_t tmp_g[4][4];  /* [bh][bw][comps] */
+         signed char tmp_r[4][4];  /* [bh][bw][comps] */
+         signed char tmp_g[4][4];  /* [bh][bw][comps] */
          for(j = 0; j < bh; ++j) {
             for(i = 0; i < bw; ++i) {
-	       tmp_r[j][i] = float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4]);
-               tmp_g[j][i] = float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4 + chan2off]);
+	       tmp_r[j][i] = (signed char)float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4]);
+              tmp_g[j][i] = (signed char)float_to_byte_tex(src_row[(y + j)*src_stride/sizeof(*src_row) + (x + i)*4 + chan2off]);
             }
          }
          util_format_signed_encode_rgtc_ubyte(dst, tmp_r, 4, 4);
@@ -437,11 +437,11 @@ util_format_rgtc2_snorm_pack_rgba_float(
 void
 util_format_rgtc2_snorm_fetch_rgba_float(float *dst, const uint8_t *src, unsigned i, unsigned j)
 {
-   int8_t tmp_r, tmp_g;
-   util_format_signed_fetch_texel_rgtc(0, (int8_t *)src, i, j, &tmp_r, 2);
-   util_format_signed_fetch_texel_rgtc(0, (int8_t *)src + 8, i, j, &tmp_g, 2);
-   dst[0] = byte_to_float_tex(tmp_r);
-   dst[1] = byte_to_float_tex(tmp_g);
+   signed char tmp_r, tmp_g;
+   util_format_signed_fetch_texel_rgtc(0, (signed char *)src, i, j, &tmp_r, 2);
+   util_format_signed_fetch_texel_rgtc(0, (signed char *)src + 8, i, j, &tmp_g, 2);
+   dst[0] = byte_to_float_tex((int8_t)tmp_r);
+   dst[1] = byte_to_float_tex((int8_t)tmp_g);
    dst[2] = 0.0;
    dst[3] = 1.0;
 }
