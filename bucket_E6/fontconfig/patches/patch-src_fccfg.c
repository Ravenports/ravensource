--- src/fccfg.c.orig	2023-01-25 05:37:45 UTC
+++ src/fccfg.c
@@ -3248,9 +3248,8 @@ FcConfigFileInfoIterGet (FcConfig		*conf
     if (name)
 	*name = FcStrdup (r->name && r->name[0] ? r->name : (const FcChar8 *) "fonts.conf");
     if (description)
-	*description = FcStrdup (!r->description ? _("No description") :
-				 dgettext (r->domain ? (const char *) r->domain : GETTEXT_PACKAGE "-conf",
-					   (const char *) r->description));
+	*description = FcStrdup (!r->description ? "No description" :
+					   (const char *) r->description);
     if (enabled)
 	*enabled = r->enabled;
 
