--- sendlib.c.orig	2023-09-09 06:55:00 UTC
+++ sendlib.c
@@ -1229,7 +1229,9 @@ static void mutt_set_encoding (BODY *b,
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
