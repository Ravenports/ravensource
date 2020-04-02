--- init.c.orig	2020-03-28 18:17:53 UTC
+++ init.c
@@ -651,6 +651,52 @@ static mbchar_table *parse_mbchar_table
   return t;
 }
 
+static int parse_ifdef (BUFFER *tmp, BUFFER *s, union pointer_long_t data, BUFFER *err)
+{
+  int i, j, res = 0;
+  BUFFER token;
+
+  memset (&token, 0, sizeof (token));
+  mutt_extract_token (tmp, s, 0);
+
+  /* is the item defined as a variable or a function? */
+  if (!(res = (mutt_option_index (tmp->data) != -1)))
+    for (i = 0; !res && i < MENU_MAX; i++)
+    {
+      struct binding_t *b = km_get_table (Menus[i].value);
+
+      if (!b)
+	continue;
+
+      for (j = 0; b[j].name; j++)
+	if (!ascii_strncasecmp (tmp->data, b[j].name, mutt_strlen (tmp->data))
+	      && (mutt_strlen (b[j].name) == mutt_strlen (tmp->data)))
+	{
+	  res = 1;
+	  break;
+	}
+    }
+
+  if (!MoreArgs (s))
+  {
+    snprintf (err->data, err->dsize, _("ifdef: too few arguments"));
+    return (-1);
+  }
+  mutt_extract_token (tmp, s, MUTT_TOKEN_SPACE);
+
+  if (res)
+  {
+    if (mutt_parse_rc_line (tmp->data, &token, err) == -1)
+    {
+      mutt_error ("Erreur: %s", err->data);
+      FREE (&token.data);
+      return (-1);
+    }
+    FREE (&token.data);
+  }
+  return 0;
+}
+
 static int parse_unignore (BUFFER *buf, BUFFER *s, union pointer_long_t udata, BUFFER *err)
 {
   do
