--- mail-time.c.orig	2023-01-09 11:20:17 UTC
+++ mail-time.c
@@ -70,9 +70,15 @@ tzlookup(const char *tz, int *off)
 	tm = localtime(&t);
 
 	/* And work out the timezone. */
+#if defined(__sun)
+	if (strcmp(tz, tzname[tm->tm_isdst > 0 ? 1 : 0]) != 0)
+		goto error;
+	*off = -timezone + (tm->tm_isdst > 0 ? 3600 : 0);
+#else
 	if (strcmp(tz, tm->tm_zone) != 0)
 		goto error;
 	*off = tm->tm_gmtoff;
+#endif
 
 	/* Restore the old timezone. */
 	if (saved_tz != NULL) {
