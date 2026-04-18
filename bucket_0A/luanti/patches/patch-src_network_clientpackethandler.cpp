--- src/network/clientpackethandler.cpp.orig	2026-02-08 11:42:38 UTC
+++ src/network/clientpackethandler.cpp
@@ -1329,7 +1329,7 @@ void Client::handleCommand_HudSetSky(Net
 		skybox.clouds = readU8(is) != 0;
 
 		// Use default skybox settings:
-		SunParams sun = SkyboxDefaults::getSunDefaults();
+		SunParams xsun = SkyboxDefaults::getSunDefaults();
 		MoonParams moon = SkyboxDefaults::getMoonDefaults();
 		StarParams stars = SkyboxDefaults::getStarDefaults();
 
@@ -1340,8 +1340,8 @@ void Client::handleCommand_HudSetSky(Net
 			skybox.fog_moon_tint = video::SColor(255, 255, 255, 255);
 			skybox.fog_sun_tint = video::SColor(255, 255, 255, 255);
 		} else {
-			sun.visible = false;
-			sun.sunrise_visible = false;
+			xsun.visible = false;
+			xsun.sunrise_visible = false;
 			moon.visible = false;
 			stars.visible = false;
 		}
@@ -1354,7 +1354,7 @@ void Client::handleCommand_HudSetSky(Net
 
 		ClientEvent *sun_event = new ClientEvent();
 		sun_event->type = CE_SET_SUN;
-		sun_event->sun_params = new SunParams(sun);
+		sun_event->sun_params = new SunParams(xsun);
 		m_client_event_queue.push(sun_event);
 
 		ClientEvent *moon_event = new ClientEvent();
@@ -1408,14 +1408,14 @@ void Client::handleCommand_HudSetSky(Net
 
 void Client::handleCommand_HudSetSun(NetworkPacket *pkt)
 {
-	SunParams sun;
+	SunParams xsun;
 
-	*pkt >> sun.visible >> sun.texture>> sun.tonemap
-		>> sun.sunrise >> sun.sunrise_visible >> sun.scale;
+	*pkt >> xsun.visible >> xsun.texture>> xsun.tonemap
+		>> xsun.sunrise >> xsun.sunrise_visible >> xsun.scale;
 
 	ClientEvent *event = new ClientEvent();
 	event->type        = CE_SET_SUN;
-	event->sun_params  = new SunParams(sun);
+	event->sun_params  = new SunParams(xsun);
 	m_client_event_queue.push(event);
 }
 
