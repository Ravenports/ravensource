--- src/fclang.c.orig	2025-06-27 03:12:04 UTC
+++ src/fclang.c
@@ -173,6 +173,7 @@ FcLangNormalize (const FcChar8 *lang)
 {
     FcChar8 *result = NULL, *s, *orig;
     char    *territory, *encoding, *modifier;
+    char    *script;
     size_t   llen, tlen = 0, mlen = 0;
 
     if (!lang || !*lang)
@@ -232,24 +233,30 @@ FcLangNormalize (const FcChar8 *lang)
 	    modifier = encoding;
 	}
     }
-    territory = strchr ((const char *)s, '_');
-    if (!territory)
-	territory = strchr ((const char *)s, '-');
+    territory = strrchr ((const char *)s, '_');
     if (territory) {
 	*territory = 0;
 	territory++;
 	tlen = strlen (territory);
     }
+    /* There might by a script component, e.g. sr_Cyrl_RS@UTF-8.  We can't assume all legal locale
+       names are in the form <lang>_<country code>.<encoding>.  If the script component is here,
+       skip it to define the language properly (e.g. "sr" instead of "sr_Cyrl") */
+    script = strchr ((const char *) s, '_');
+    if (script)
+    {
+        *script = 0;
+    }
     llen = strlen ((const char *)s);
     if (llen < 2 || llen > 3) {
-	fprintf (stderr, "Fontconfig warning: ignoring %s: not a valid language tag\n",
-	         lang);
+	fprintf (stderr, "Fontconfig warning: ignoring %s: not a valid language tag (%s)\n",
+	         s, lang);
 	goto bail0;
     }
     if (territory && (tlen < 2 || tlen > 3) &&
         !(territory[0] == 'z' && tlen < 5)) {
-	fprintf (stderr, "Fontconfig warning: ignoring %s: not a valid region tag\n",
-	         lang);
+	fprintf (stderr, "Fontconfig warning: ignoring %s: not a valid region tag (%s)\n",
+	         territory, lang);
 	goto bail0;
     }
     if (territory)
