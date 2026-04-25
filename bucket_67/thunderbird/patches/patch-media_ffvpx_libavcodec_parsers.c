--- media/ffvpx/libavcodec/parsers.c.orig	2026-04-17 17:48:03 UTC
+++ media/ffvpx/libavcodec/parsers.c
@@ -111,7 +111,7 @@ extern const FFCodecParser ff_xwd_parser
 const AVCodecParser *av_parser_iterate(void **opaque)
 {
     uintptr_t i = (uintptr_t)*opaque;
-    const FFCodecParser *p = parser_list[i];
+    const FFCodecParser *p = (const FFCodecParser *)parser_list[i];
 
     if (p) {
         *opaque = (void*)(i + 1);
