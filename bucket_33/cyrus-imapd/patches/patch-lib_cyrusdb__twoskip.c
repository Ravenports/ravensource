--- lib/cyrusdb_twoskip.c.orig	2026-09-09 01:06:41 UTC
+++ lib/cyrusdb_twoskip.c
@@ -448,6 +448,7 @@ static int recovery2(struct dbengine *db
 #define SIZE(db) mappedfile_size((db)->mf)
 #define FNAME(db) mappedfile_fname((db)->mf)
 
+#undef roundup
 /* calculate padding size */
 static inline size_t roundup(size_t record_size, int howfar)
 {
