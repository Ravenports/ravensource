--- usr.sbin/smtpd/proxy.c.orig	2025-07-30 20:26:49 UTC
+++ usr.sbin/smtpd/proxy.c
@@ -333,7 +333,7 @@ proxy_translate_ss(struct proxy_session
 {
 	struct sockaddr_in *sin = (struct sockaddr_in *) &s->ss;
 	struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) &s->ss;
-	struct sockaddr_un *sun = (struct sockaddr_un *) &s->ss;
+	struct sockaddr_un *xsun = (struct sockaddr_un *) &s->ss;
 	size_t sun_len;
 
 	switch (s->hdr.fam) {
@@ -362,13 +362,13 @@ proxy_translate_ss(struct proxy_session
 		memset(&s->ss, 0, sizeof(s->ss));
 		sun_len = strnlen(s->addr.un.src_addr,
 		    sizeof(s->addr.un.src_addr));
-		if (sun_len > sizeof(sun->sun_path)) {
+		if (sun_len > sizeof(xsun->sun_path)) {
 			proxy_error(s, "address translation", "Unix socket path"
 			    " longer than supported");
 			return (-1);
 		}
-		sun->sun_family = AF_UNIX;
-		memcpy(sun->sun_path, s->addr.un.src_addr, sun_len);
+		xsun->sun_family = AF_UNIX;
+		memcpy(xsun->sun_path, s->addr.un.src_addr, sun_len);
 		break;
 
 	default:
