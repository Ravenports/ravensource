--- joe/main.c.orig	2026-04-23 15:22:34 UTC
+++ joe/main.c
@@ -754,8 +754,10 @@ int main(int argc, char **real_argv, con
 			cstart ((BW *)maint->curwin->object, NULL, NULL, NULL, NULL, 0, 1, NULL, SHELL_TYPE_RAW);
 			/* Close stdin, so that if user kills the copying the program feeding stdin sees a SIGPIPE */
 			/* It won't if there are any extra file descriptors open */
-			fclose(stdin);
-			stdin = fopen("/dev/tty", "rb");
+			if (freopen("/dev/tty", "rb", stdin) == NULL) {
+				fprintf(stderr, "joe: could not reopen /dev/tty\n");
+				exit(1);
+			}
 		}
 	}
 
