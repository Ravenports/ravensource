--- sndiod/sock.c.orig	2026-10-15 10:05:00 UTC
+++ sndiod/sock.c
@@ -661,11 +661,13 @@ sock_auth(struct sock *f)
 	/*
 	 * root bypasses any authentication checks and has no session
 	 */
+#if !defined(__sun)
 	if (getpeereid(f->fd, &euid, &egid) == 0 && euid == 0) {
 		f->pstate = SOCK_HELLO;
 		f->sesrefs = 0;
 		return 1;
 	}
+#endif
 
 	if (sock_sesrefs == 0) {
 		/* start a new session */
