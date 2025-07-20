--- lib/plat/unix/unix-spawn.c.orig	2025-07-12 14:25:04 UTC
+++ lib/plat/unix/unix-spawn.c
@@ -465,7 +465,7 @@ lws_spawn_piped(const struct lws_spawn_p
 	if (lsp->info.disable_ctrlc)
 		/* stops non-daemonized main processess getting SIGINT
 		 * from TTY */
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		setpgid(0, 0);
 #else
 		setpgrp();
