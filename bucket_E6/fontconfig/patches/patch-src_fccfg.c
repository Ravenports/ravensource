--- src/fccfg.c.orig	2026-07-09 09:30:10 UTC
+++ src/fccfg.c
@@ -3237,7 +3237,7 @@ FcConfigFileInfoIterGet (FcConfig
     if (name)
 	*name = FcStrCopy (r->name && r->name[0] ? r->name : (const FcChar8 *)"fonts.conf");
     if (description)
-	*description = FcStrCopy ((const FcChar8 *)(!r->description ? _ ("No description") : dgettext (r->domain ? (const char *)r->domain : GETTEXT_PACKAGE "-conf", (const char *)r->description)));
+	*description = FcStrCopy ((const FcChar8 *)(!r->description ? "No description" : (const char *)r->description));
     if (enabled)
 	*enabled = r->enabled;
 
