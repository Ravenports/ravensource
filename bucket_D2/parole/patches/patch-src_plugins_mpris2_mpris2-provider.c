--- src/plugins/mpris2/mpris2-provider.c.orig	2025-05-21 06:46:43 UTC
+++ src/plugins/mpris2/mpris2-provider.c
@@ -196,7 +196,7 @@ static GVariant* mpris_Root_get_DesktopE
 static GVariant* mpris_Root_get_SupportedUriSchemes(GError **error, Mpris2Provider *provider) {
     return g_variant_parse(G_VARIANT_TYPE("as"),
         "['cdda', 'dvd', 'file', 'icy', 'icyx', 'mms', 'mmsh', 'net', "
-        "'pnm', 'rtmp', 'rtp', 'rtsp', 'uvox']", NULL, NULL, NULL);
+        "'pnm', 'rtp', 'rtsp', 'uvox']", NULL, NULL, NULL);
 }
 
 static GVariant* mpris_Root_get_SupportedMimeTypes(GError **error, Mpris2Provider *provider) {
