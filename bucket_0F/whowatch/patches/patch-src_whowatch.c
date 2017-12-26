--- src/whowatch.c.orig	2013-10-07 12:11:29 UTC
+++ src/whowatch.c
@@ -436,12 +436,16 @@ int main(int argc, char **argv)
 		gettimeofday(&after, 0);
 		tv.tv_sec -= (after.tv_sec - before.tv_sec);
 		if(retval > 0) {
-			int key = read_key();
+			key = getkey();
+			if(key == KBD_MORE) {
+				usleep(10000);
+				key = getkey();
+			}
 			key_action(key);
 		}
 		if(tv.tv_sec <= 0) {
 			ticks++;
-			periodic();
+			main_periodic();
 			tv.tv_sec = TIMEOUT;
 		}
 #endif
