--- commands.c.orig	2020-02-21 20:17:47 UTC
+++ commands.c
@@ -285,7 +285,7 @@ int mutt_display_message (HEADER *cur)
     {
       if (cur->security & GOODSIGN)
       {
-	if (!crypt_smime_verify_sender(cur))
+	if (option(OPTSMIMENOSENDER) || !crypt_smime_verify_sender(cur))
 	  mutt_message ( _("S/MIME signature successfully verified."));
 	else
 	  mutt_error ( _("S/MIME certificate owner does not match sender."));
