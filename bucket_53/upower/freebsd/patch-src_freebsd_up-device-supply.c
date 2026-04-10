--- src/freebsd/up-device-supply.c.orig	2026-02-10 12:01:59.000000000 -0000
+++ src/freebsd/up-device-supply.c
@@ -250,7 +250,7 @@ up_device_supply_battery_set_properties
 		      "energy", cap,
 		      "energy-full", lastfull,
 		      "energy-full-design", dcap,
-		      "energy-rate", rate,
+		      "energy-rate", (battinfo.battinfo.state & ACPI_BATT_STAT_CHARGING) ? -rate : rate,
 		      "energy-empty", lcap,
 		      "voltage", volt,
 		      "capacity", capacity,
