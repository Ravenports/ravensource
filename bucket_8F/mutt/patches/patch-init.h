--- init.h.orig	2020-03-28 18:17:53 UTC
+++ init.h
@@ -1079,6 +1079,11 @@ struct option_t MuttVars[] = {
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
@@ -3021,6 +3026,13 @@ struct option_t MuttVars[] = {
   ** In either case, a missing real name will be filled in afterwards
   ** using the value of $$realname.
   */
+  { "reverse_reply",	DT_BOOL, R_NONE, {.l=OPTREVREPLY}, {.l=0} },
+  /*
+  ** .pp
+  ** When set, this variable uses the name from your aliases in the To and Cc
+  ** headers of reply mails you send, like $reverse_alias does in the index.
+  ** When unset, the headers taken from the original mail are left unchanged.
+  */
   { "rfc2047_parameters", DT_BOOL, R_NONE, {.l=OPTRFC2047PARAMS}, {.l=0} },
   /*
   ** .pp
@@ -3511,6 +3523,15 @@ struct option_t MuttVars[] = {
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
@@ -4503,6 +4524,7 @@ static int parse_lists (BUFFER *, BUFFER
 static int parse_unlists (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
 static int parse_alias (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
 static int parse_unalias (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
+static int parse_ifdef (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
 static int parse_echo (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
 static int parse_ignore (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
 static int parse_unignore (BUFFER *, BUFFER *, union pointer_long_t, BUFFER *);
@@ -4567,6 +4589,7 @@ const struct command_t Commands[] = {
   { "hdr_order",	parse_list,		{.p=&HeaderOrderList} },
 #ifdef HAVE_ICONV
   { "iconv-hook",	mutt_parse_hook,	{.l=MUTT_ICONVHOOK} },
+  { "ifdef",		parse_ifdef,		{.l=0} },
 #endif
   { "ignore",		parse_ignore,		{.l=0} },
   { "index-format-hook",mutt_parse_idxfmt_hook, {.l=MUTT_IDXFMTHOOK} },
