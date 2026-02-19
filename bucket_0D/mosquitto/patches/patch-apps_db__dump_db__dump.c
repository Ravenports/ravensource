--- apps/db_dump/db_dump.c.orig	2026-02-09 09:29:46 UTC
+++ apps/db_dump/db_dump.c
@@ -42,6 +42,10 @@ Contributors:
 #include <sys/endian.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <netinet/in.h> // for ntohl and friends
+#endif
+
 struct client_data {
 	UT_hash_handle hh_id;
 	char *id;
