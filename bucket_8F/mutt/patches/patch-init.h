--- init.h.orig	2025-09-29 06:52:07 UTC
+++ init.h
@@ -1304,6 +1304,11 @@ struct option_t MuttVars[] = {
   ** sent to both the list and your address, resulting in two copies
   ** of the same email for you.
   */
+  { "force_base64",   DT_BOOL, R_NONE, {.l=OPTFORCEBASE64}, {.l=0} },
+  /*
+  ** .pp
+  ** If you need to encode all text parts to base64, set this option.
+  */
   { "force_name",	DT_BOOL, R_NONE, {.l=OPTFORCENAME}, {.l=0} },
   /*
   ** .pp
@@ -3919,6 +3924,15 @@ struct option_t MuttVars[] = {
   ** to determine the key to use. It will ask you to supply a key, if it can't find one.
   ** (S/MIME only)
   */
+  { "smime_dont_check_sender",	DT_BOOL, R_NONE, {.l=OPTSMIMENOSENDER}, {.l=0} },
+  /*
+  ** .pp
+  ** This flag controls wether you want the skip the check for the sender's
+  ** email address against the email address stored in the certificate. 
+  ** This can be useful if most of your email senders use SMIMEv3 which no
+  ** longer needs email-addresses as part of the certificates.
+  ** It is not set by default.
+  */
   { "smime_self_encrypt_as",	DT_SYN,  R_NONE, {.p="smime_default_key"}, {.p=0} },
   { "smime_default_key",		DT_STR,	 R_NONE, {.p=&SmimeDefaultKey}, {.p=0} },
   /*
