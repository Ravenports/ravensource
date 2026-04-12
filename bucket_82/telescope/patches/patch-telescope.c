--- telescope.c.orig	2025-05-10 13:20:51 UTC
+++ telescope.c
@@ -1034,18 +1034,18 @@ start_child(enum telescope_process p, co
 static void
 send_url(const char *url)
 {
-	struct sockaddr_un	 sun;
+	struct sockaddr_un	 xsun;
 	struct imsgbuf		 ibuf;
 	int			 ctl_sock;
 
 	if ((ctl_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
 		err(1, "socket");
 
-	memset(&sun, 0, sizeof(sun));
-	sun.sun_family = AF_UNIX;
-	strlcpy(sun.sun_path, ctlsock_path, sizeof(sun.sun_path));
+	memset(&xsun, 0, sizeof(xsun));
+	xsun.sun_family = AF_UNIX;
+	strlcpy(xsun.sun_path, ctlsock_path, sizeof(xsun.sun_path));
 
-	if (connect(ctl_sock, (struct sockaddr *)&sun, sizeof(sun)) == -1)
+	if (connect(ctl_sock, (struct sockaddr *)&xsun, sizeof(xsun)) == -1)
 		err(1, "connect: %s", ctlsock_path);
 
 	if (imsgbuf_init(&ibuf, ctl_sock) == -1)
