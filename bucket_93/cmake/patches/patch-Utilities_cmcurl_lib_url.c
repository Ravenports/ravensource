--- Utilities/cmcurl/lib/url.c.orig	2023-05-18 17:49:44 UTC
+++ Utilities/cmcurl/lib/url.c
@@ -638,6 +638,10 @@ CURLcode Curl_init_userdefined(struct Cu
     CURL_HTTP_VERSION_1_1
 #endif
     ;
+#if defined(__FreeBSD__)
+  /* different handling of signals and threads */
+  set->no_signal = TRUE;
+#endif
   Curl_http2_init_userset(set);
   set->quick_exit = 0L;
   return result;
