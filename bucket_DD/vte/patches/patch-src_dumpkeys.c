--- src/dumpkeys.c.orig	2023-04-13 09:57:27 UTC
+++ src/dumpkeys.c
@@ -161,7 +161,15 @@ main(int argc, char **argv)
 	}
 	original = tcattr;
 	signal(SIGINT, sigint_handler);
+#ifdef __sun__
+	tcattr.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+	tcattr.c_oflag &= ~OPOST;
+	tcattr.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+	tcattr.c_cflag &= ~(CSIZE|PARENB);
+	tcattr.c_cflag |= CS8;
+#else
 	cfmakeraw(&tcattr);
+#endif
 	if (tcsetattr(STDIN_FILENO, TCSANOW, &tcattr) != 0) {
 		perror("tcsetattr");
 		return 1;
