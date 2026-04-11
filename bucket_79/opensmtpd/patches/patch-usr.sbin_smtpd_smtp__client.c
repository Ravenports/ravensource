--- usr.sbin/smtpd/smtp_client.c.orig	2025-07-30 20:26:49 UTC
+++ usr.sbin/smtpd/smtp_client.c
@@ -62,8 +62,13 @@ enum {
 	STATE_LAST
 };
 
+#ifdef __sun
+#define base64_encode 	b64_ntop
+#define base64_decode	b64_pton
+#else
 #define base64_encode	__b64_ntop
 #define base64_decode	__b64_pton
+#endif
 
 #define FLAG_TLS		0x01
 #define FLAG_TLS_VERIFIED	0x02
