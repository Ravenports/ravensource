--- sendlib.c.orig	2020-03-28 18:17:53 UTC
+++ sendlib.c
@@ -1218,7 +1218,9 @@ static void mutt_set_encoding (BODY *b,
   if (b->type == TYPETEXT)
   {
     char *chsname = mutt_get_body_charset (send_charset, sizeof (send_charset), b);
-    if ((info->lobin && ascii_strncasecmp (chsname, "iso-2022", 8)) || info->linemax > 990 || (info->from && option (OPTENCODEFROM)))
+    if (option (OPTFORCEBASE64))
+      b->encoding = ENCBASE64;
+    else if ((info->lobin && ascii_strncasecmp (chsname, "iso-2022", 8)) || info->linemax > 990 || (info->from && option (OPTENCODEFROM)))
       b->encoding = ENCQUOTEDPRINTABLE;
     else if (info->hibin)
       b->encoding = option (OPTALLOW8BIT) ? ENC8BIT : ENCQUOTEDPRINTABLE;
@@ -2974,6 +2976,35 @@ static void set_noconv_flags (BODY *b, s
   }
 }
 
+/* given a list of addresses, return a list of reverse_alias'ed addresses */
+ADDRESS *mutt_reverse_address (ADDRESS *addr)
+{
+  ADDRESS *top,*tmp,*alias;
+
+  if (addr == NULL)
+    return NULL;
+
+  if ((alias = alias_reverse_lookup (addr)) && alias->personal) {
+    tmp = rfc822_cpy_adr_real(alias);
+    tmp->next = addr->next;
+    addr->next = NULL;
+    rfc822_free_address(&addr);
+    addr = tmp;
+  }
+
+  for (top = addr; top->next != NULL; top = tmp) {
+    tmp = top->next;
+    if ((alias = alias_reverse_lookup (tmp)) && alias->personal) {
+      top->next = rfc822_cpy_adr_real(alias);
+      top->next->next = tmp->next;
+      tmp->next = NULL;
+      rfc822_free_address(&tmp);
+      tmp = top->next;
+    }
+  }
+  return addr;
+}
+
 int mutt_write_fcc (const char *path, HEADER *hdr, const char *msgid, int post, const char *fcc)
 {
   CONTEXT f;
