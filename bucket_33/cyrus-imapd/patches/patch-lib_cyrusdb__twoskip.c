--- lib/cyrusdb_twoskip.c.orig	2024-08-16 00:24:23 UTC
+++ lib/cyrusdb_twoskip.c
@@ -450,6 +450,7 @@ static int recovery2(struct dbengine *db
 #define SIZE(db) mappedfile_size((db)->mf)
 #define FNAME(db) mappedfile_fname((db)->mf)
 
+#undef roundup
 /* calculate padding size */
 static inline size_t roundup(size_t record_size, int howfar)
 {
