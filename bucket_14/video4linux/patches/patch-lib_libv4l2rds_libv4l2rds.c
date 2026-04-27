--- lib/libv4l2rds/libv4l2rds.c.orig	2023-02-24 16:40:23 UTC
+++ lib/libv4l2rds/libv4l2rds.c
@@ -1039,6 +1039,14 @@ static time_t rds_decode_mjd(const struc
 	new_time.tm_year = y;
 	/* offset (submitted by RDS) that was used to compute the local time,
 	 * expressed in multiples of half hours, bit 5 indicates -/+ */
+#if defined(__sun)
+	time_t res = mktime(&new_time);
+	if (priv_state->utc_offset & 0x20)
+		res -= offset * 1800;
+	else
+		res += offset * 1800;
+	return res;
+#else
 	if (priv_state->utc_offset & 0x20)
 		new_time.tm_gmtoff = -offset * 1800;
 	else
@@ -1046,6 +1054,7 @@ static time_t rds_decode_mjd(const struc
 
 	/* convert tm struct to time_t value and return it */
 	return mktime(&new_time);
+#endif
 }
 
 /* group 4: Date and Time */
