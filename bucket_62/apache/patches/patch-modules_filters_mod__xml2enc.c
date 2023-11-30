--- modules/filters/mod_xml2enc.c.orig	2020-02-21 00:33:40 UTC
+++ modules/filters/mod_xml2enc.c
@@ -209,7 +209,7 @@ static void sniff_encoding(request_rec*
   
     /* to sniff, first we look for BOM */
     if (ctx->xml2enc == XML_CHAR_ENCODING_NONE) {
-        ctx->xml2enc = xmlDetectCharEncoding((const xmlChar*)ctx->buf,
+        ctx->xml2enc = xmlDetectCharEncoding((const unsigned char*)ctx->buf,
                                              ctx->bytes); 
         if (HAVE_ENCODING(ctx->xml2enc)) {
             ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r, APLOGNO(01432)
