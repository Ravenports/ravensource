--- commands.c.orig	2023-08-18 03:03:18 UTC
+++ commands.c
@@ -302,7 +302,7 @@ int mutt_display_message (HEADER *cur)
     {
       if (cur->security & GOODSIGN)
       {
-	if (!crypt_smime_verify_sender(cur))
+	if (option(OPTSMIMENOSENDER) || !crypt_smime_verify_sender(cur))
 	  mutt_message ( _("S/MIME signature successfully verified."));
 	else
 	  mutt_error ( _("S/MIME certificate owner does not match sender."));
