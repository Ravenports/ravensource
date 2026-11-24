--- src/fccfg.c.orig	2026-11-18 11:53:03 UTC
+++ src/fccfg.c
@@ -3276,7 +3276,7 @@ FcConfigFileInfoIterGet (FcConfig
     if (name)
 	*name = FcStrCopy (r->name && r->name[0] ? r->name : (const FcChar8 *)"fonts.conf");
     if (description)
-	*description = FcStrCopy ((const FcChar8 *)(!r->description ? _ ("No description") : dgettext (r->domain ? (const char *)r->domain : GETTEXT_PACKAGE "-conf", (const char *)r->description)));
+	*description = FcStrCopy ((const FcChar8 *)(!r->description ? "No description" : (const char *)r->description));
     if (enabled)
 	*enabled = r->enabled;
 
