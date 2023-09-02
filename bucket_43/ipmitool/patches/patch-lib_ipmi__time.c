--- lib/ipmi_time.c.orig	2022-09-01 18:42:31 UTC
+++ lib/ipmi_time.c
@@ -105,7 +105,9 @@ ipmi_strftime(char *s, size_t max, const
 		 * the timezone offset.
 		 */
 		gmtime_r(&stamp, &tm);
+#if !defined(__FreeBSD__)
 		daylight = -1;
+#endif
 	} else {
 		/*
 		 * The user wants the time reported in local time zone.
