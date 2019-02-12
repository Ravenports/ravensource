--- ext/vpx/gstvpxdec.c.orig	2018-01-25 19:41:41 UTC
+++ ext/vpx/gstvpxdec.c
@@ -62,6 +62,7 @@ gst_vpx_dec_post_processing_flags_get_ty
     {C_FLAGS (VP8_DEBLOCK), "Deblock", "deblock"},
     {C_FLAGS (VP8_DEMACROBLOCK), "Demacroblock", "demacroblock"},
     {C_FLAGS (VP8_ADDNOISE), "Add noise", "addnoise"},
+#if 0 // VPX_1.8 doesn't support
     {C_FLAGS (VP8_DEBUG_TXT_FRAME_INFO),
           "Print frame information",
         "visualize-frame-info"},
@@ -74,6 +75,7 @@ gst_vpx_dec_post_processing_flags_get_ty
     {C_FLAGS (VP8_DEBUG_TXT_RATE_INFO),
           "Print video rate info",
         "visualize-rate-info"},
+#endif
     {C_FLAGS (VP8_MFQE), "Multi-frame quality enhancement", "mfqe"},
     {0, NULL, NULL}
   };
