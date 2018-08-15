Index: saslauthd/saslcache.c
diff -u -p saslauthd/saslcache.c.orig saslauthd/saslcache.c
--- saslauthd/saslcache.c.orig	2012-01-27 23:31:36 UTC
+++ saslauthd/saslcache.c
@@ -137,7 +137,7 @@ int main(int argc, char **argv) {
 	}
 
 	table_stats = shm_base + 64;
-	(char *)table = (char *)table_stats + 128;
+	table = (struct bucket *)((char *)table_stats + 128);
 
 	if (dump_stat_info == 0 && dump_user_info == 0)
 		dump_stat_info = 1;
