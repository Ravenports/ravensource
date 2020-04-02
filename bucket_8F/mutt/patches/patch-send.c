--- send.c.orig	2020-03-28 18:17:53 UTC
+++ send.c
@@ -723,6 +723,10 @@ void mutt_fix_reply_recipients (ENVELOPE
   /* the CC field can get cluttered, especially with lists */
   env->to = mutt_remove_duplicates (env->to);
   env->cc = mutt_remove_duplicates (env->cc);
+  if (option (OPTREVREPLY)){
+	env->to = mutt_reverse_address (env->to);
+	env->cc = mutt_reverse_address (env->cc);
+  }
   env->cc = mutt_remove_xrefs (env->to, env->cc);
 
   if (env->cc && !env->to)
