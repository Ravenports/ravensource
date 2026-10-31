--- lib/plat/unix/unix-spawn.c.orig	2026-10-30 11:39:27 UTC
+++ lib/plat/unix/unix-spawn.c
@@ -1032,7 +1032,7 @@ lws_spawn_piped(const struct lws_spawn_p
 		 * lws_spawn_piped_kill_child_process() would no longer refer to
 		 * the group of children spawned without disable_ctrlc.
 		 */
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		setpgid(0, 0);
 #else
 		setpgrp();
