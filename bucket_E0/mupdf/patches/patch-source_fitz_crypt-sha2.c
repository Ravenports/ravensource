$NetBSD: patch-ae,v 1.5 2016/02/04 11:50:24 leot Exp $

Avoid namespace conflicts with bswap(3).

--- source/fitz/crypt-sha2.c.orig	2025-07-23 10:59:11 UTC
+++ source/fitz/crypt-sha2.c
@@ -19,7 +19,7 @@ static inline int isbigendian(void)
 	return *(char*)&one == 0;
 }
 
-static inline unsigned int bswap32(unsigned int num)
+static inline unsigned int mup_bswap32(unsigned int num)
 {
 	return	( (((num) << 24))
 		| (((num) << 8) & 0x00FF0000)
@@ -27,7 +27,7 @@ static inline unsigned int bswap32(unsig
 		| (((num) >> 24)) );
 }
 
-static inline uint64_t bswap64(uint64_t num)
+static inline uint64_t mup_bswap64(uint64_t num)
 {
 	return ( (((num) << 56))
 		| (((num) << 40) & 0x00FF000000000000ULL)
@@ -101,7 +101,7 @@ transform256(unsigned int state[8], unsi
 	/* ensure big-endian integers */
 	if (!isbigendian())
 		for (j = 0; j < 16; j++)
-			data[j] = bswap32(data[j]);
+			data[j] = mup_bswap32(data[j]);
 
 	/* Copy state[] to working vars. */
 	memcpy(T, state, sizeof(T));
@@ -194,8 +194,8 @@ void fz_sha256_final(fz_sha256 *context,
 
 	if (!isbigendian())
 	{
-		context->buffer.u32[14] = bswap32(context->count[1]);
-		context->buffer.u32[15] = bswap32(context->count[0]);
+		context->buffer.u32[14] = mup_bswap32(context->count[1]);
+		context->buffer.u32[15] = mup_bswap32(context->count[0]);
 	}
 	else
 	{
@@ -206,7 +206,7 @@ void fz_sha256_final(fz_sha256 *context,
 
 	if (!isbigendian())
 		for (j = 0; j < 8; j++)
-			context->state[j] = bswap32(context->state[j]);
+			context->state[j] = mup_bswap32(context->state[j]);
 
 	memcpy(digest, &context->state[0], 32);
 	memset(context, 0, sizeof(fz_sha256));
@@ -273,7 +273,7 @@ transform512(uint64_t state[8], uint64_t
 	/* ensure big-endian integers */
 	if (!isbigendian())
 		for (j = 0; j < 16; j++)
-			data[j] = bswap64(data[j]);
+			data[j] = mup_bswap64(data[j]);
 
 	/* Copy state[] to working vars. */
 	memcpy(T, state, sizeof(T));
@@ -366,8 +366,8 @@ void fz_sha512_final(fz_sha512 *context,
 
 	if (!isbigendian())
 	{
-		context->buffer.u64[14] = bswap64(context->count[1]);
-		context->buffer.u64[15] = bswap64(context->count[0]);
+		context->buffer.u64[14] = mup_bswap64(context->count[1]);
+		context->buffer.u64[15] = mup_bswap64(context->count[0]);
 	}
 	else
 	{
@@ -378,7 +378,7 @@ void fz_sha512_final(fz_sha512 *context,
 
 	if (!isbigendian())
 		for (j = 0; j < 8; j++)
-			context->state[j] = bswap64(context->state[j]);
+			context->state[j] = mup_bswap64(context->state[j]);
 
 	memcpy(digest, &context->state[0], 64);
 	memset(context, 0, sizeof(fz_sha512));
