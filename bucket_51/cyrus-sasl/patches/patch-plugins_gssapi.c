--- plugins/gssapi.c.orig	2012-01-27 23:31:36 UTC
+++ plugins/gssapi.c
@@ -1490,8 +1490,10 @@ static int gssapi_client_mech_step(void
     *clientout = NULL;
     *clientoutlen = 0;
     
+#if 0
     params->utils->log(NULL, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
