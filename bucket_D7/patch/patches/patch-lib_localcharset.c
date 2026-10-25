--- lib/localcharset.c.orig	2026-10-21 15:05:09 UTC
+++ lib/localcharset.c
@@ -92,7 +92,7 @@ struct table_entry
 /* Table of platform-dependent mappings, sorted in ascending order.  */
 static const struct table_entry alias_table[] =
   {
-#  if defined __FreeBSD__                                   /* FreeBSD */
+#  if defined __FreeBSD__ || defined __DragonFly__   /* FreeBSD */
   /*{ "ARMSCII-8",  "ARMSCII-8" },*/
     { "Big5",       "BIG5" },
     { "C",          "ASCII" },
@@ -544,7 +544,7 @@ struct table_entry
 /* Table of platform-dependent mappings, sorted in ascending order.  */
 static const struct table_entry locale_table[] =
   {
-# if defined __FreeBSD__                                    /* FreeBSD 4.2 */
+# if defined __FreeBSD__ || defined __DragonFly__    /* FreeBSD 4.2 */
     { "cs_CZ.ISO_8859-2",  "ISO-8859-2" },
     { "da_DK.DIS_8859-15", "ISO-8859-15" },
     { "da_DK.ISO_8859-1",  "ISO-8859-1" },
