--- src/app/app.cc.orig	2024-10-19 19:25:25 UTC
+++ src/app/app.cc
@@ -3971,7 +3971,15 @@ main(int argc,
                struct termios tcattr;
                if (tcgetattr(STDIN_FILENO, &tcattr) == 0) {
                        saved_tcattr = tcattr;
+#ifdef __sun__
+	tcattr.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+	tcattr.c_oflag &= ~OPOST;
+	tcattr.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+	tcattr.c_cflag &= ~(CSIZE|PARENB);
+	tcattr.c_cflag |= CS8;
+#else
                        cfmakeraw(&tcattr);
+#endif
                        if (tcsetattr(STDIN_FILENO, TCSANOW, &tcattr) == 0)
                                reset_termios = true;
                }
