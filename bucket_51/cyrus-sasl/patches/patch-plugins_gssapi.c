--- plugins/gssapi.c.orig	2022-02-18 21:53:25 UTC
+++ plugins/gssapi.c
@@ -1668,8 +1668,10 @@ static int gssapi_client_mech_step(void
     if (clientoutlen)
         *clientoutlen = 0;
     
+#if 0
     params->utils->log(params->utils->conn, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
