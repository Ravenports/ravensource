--- media/ffvpx/libavcodec/parser_list.c.orig	2026-04-17 17:48:03 UTC
+++ media/ffvpx/libavcodec/parser_list.c
@@ -2,9 +2,9 @@
 
 static const AVCodecParser * const parser_list[] = {
 #if CONFIG_VP8_PARSER
-    &ff_vp8_parser,
+    (const AVCodecParser *)&ff_vp8_parser,
 #endif
 #if CONFIG_VP9_PARSER
-    &ff_vp9_parser,
+    (const AVCodecParser *)&ff_vp9_parser,
 #endif
     NULL };
