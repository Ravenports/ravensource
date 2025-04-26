--- src/fccfg.c.orig	2025-04-11 06:47:01 UTC
+++ src/fccfg.c
@@ -3130,7 +3130,7 @@ FcConfigFileInfoIterGet (FcConfig
     if (name)
 	*name = FcStrdup (r->name && r->name[0] ? r->name : (const FcChar8 *)"fonts.conf");
     if (description)
-	*description = FcStrdup (!r->description ? _ ("No description") : dgettext (r->domain ? (const char *)r->domain : GETTEXT_PACKAGE "-conf", (const char *)r->description));
+	*description = FcStrdup (!r->description ? "No description" : (const char *) r->description);
     if (enabled)
 	*enabled = r->enabled;
 
