--- src/freebsd/up-device-supply.c.orig	2022-09-08 20:53:32.327516000 +0200
+++ src/freebsd/up-device-supply.c	2022-09-08 20:55:09.728351000 +0200
@@ -250,7 +250,7 @@
 		      "energy", cap,
 		      "energy-full", lastfull,
 		      "energy-full-design", dcap,
-		      "energy-rate", rate,
+		      "energy-rate", (battinfo.battinfo.state & ACPI_BATT_STAT_CHARGING) ? -rate : rate,
 		      "energy-empty", lcap,
 		      "voltage", volt,
 		      "capacity", capacity,
