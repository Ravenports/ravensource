--- src/skyparams.h.orig	2026-04-14 20:04:31 UTC
+++ src/skyparams.h
@@ -115,14 +115,14 @@ public:
 
 	static const SunParams getSunDefaults()
 	{
-		SunParams sun;
-		sun.visible = true;
-		sun.sunrise_visible = true;
-		sun.texture = "sun.png";
-		sun.tonemap = "sun_tonemap.png";
-		sun.sunrise = "sunrisebg.png";
-		sun.scale = 1;
-		return sun;
+		SunParams xsun;
+		xsun.visible = true;
+		xsun.sunrise_visible = true;
+		xsun.texture = "sun.png";
+		xsun.tonemap = "sun_tonemap.png";
+		xsun.sunrise = "sunrisebg.png";
+		xsun.scale = 1;
+		return xsun;
 	}
 
 	static const MoonParams getMoonDefaults()
