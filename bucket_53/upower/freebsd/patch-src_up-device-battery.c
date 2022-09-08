--- src/up-device-battery.c.orig	2022-09-08 20:57:32.863720000 +0200
+++ src/up-device-battery.c	2022-09-08 20:58:59.388754000 +0200
@@ -125,7 +125,7 @@
 			continue;
 
 		/* Stop searching if the new reference is further away from the long timeout. */
-		if (abs(UP_DAEMON_LONG_TIMEOUT * G_USEC_PER_SEC - abs (td)) > abs(UP_DAEMON_SHORT_TIMEOUT * G_USEC_PER_SEC - ref_td))
+		if (labs(UP_DAEMON_LONG_TIMEOUT * G_USEC_PER_SEC - labs (td)) > labs(UP_DAEMON_SHORT_TIMEOUT * G_USEC_PER_SEC - ref_td))
 			break;
 
 		ref_td = td;
@@ -155,7 +155,7 @@
 	 */
 	if (cur->state == UP_DEVICE_STATE_UNKNOWN) {
 		/* Consider a rate of 0.5W as "no change", otherwise set CHARGING/DISCHARGING */
-		if (abs(energy_rate) < 0.5)
+		if (fabs(energy_rate) < 0.5)
 			return;
 		else if (energy_rate < 0.0)
 			cur->state = UP_DEVICE_STATE_DISCHARGING;
