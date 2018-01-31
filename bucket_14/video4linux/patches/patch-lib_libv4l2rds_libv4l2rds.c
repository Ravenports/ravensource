--- lib/libv4l2rds/libv4l2rds.c.orig	2014-08-22 14:59:47 UTC
+++ lib/libv4l2rds/libv4l2rds.c
@@ -1046,12 +1046,14 @@ static time_t rds_decode_mjd(const struc
 	new_time.tm_mday = d;
 	new_time.tm_mon = m - 1;
 	new_time.tm_year = y;
+#ifndef __sun__
 	/* offset (submitted by RDS) that was used to compute the local time,
 	 * expressed in multiples of half hours, bit 5 indicates -/+ */
 	if (priv_state->utc_offset & 0x20)
 		new_time.tm_gmtoff = -offset * 1800;
 	else
 		new_time.tm_gmtoff = offset * 1800;
+#endif
 
 	/* convert tm struct to time_t value and return it */
 	return mktime(&new_time);
