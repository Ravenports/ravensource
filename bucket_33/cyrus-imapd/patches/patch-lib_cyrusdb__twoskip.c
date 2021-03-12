--- lib/cyrusdb_twoskip.c.orig	2021-03-09 04:32:13 UTC
+++ lib/cyrusdb_twoskip.c
@@ -449,6 +449,7 @@ static int recovery2(struct dbengine *db
 #define SIZE(db) mappedfile_size((db)->mf)
 #define FNAME(db) mappedfile_fname((db)->mf)
 
+#undef roundup
 /* calculate padding size */
 static size_t roundup(size_t record_size, int howfar)
 {
