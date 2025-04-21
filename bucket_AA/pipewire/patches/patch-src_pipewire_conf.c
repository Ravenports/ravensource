--- src/pipewire/conf.c.orig	2025-04-14 09:46:02 UTC
+++ src/pipewire/conf.c
@@ -18,11 +18,9 @@
 #ifdef HAVE_PWD_H
 #include <pwd.h>
 #endif
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
 #ifndef O_PATH
 #define O_PATH 0
 #endif
-#endif
 
 #include <spa/utils/cleanup.h>
 #include <spa/utils/result.h>
@@ -358,7 +356,7 @@ int pw_conf_save_state(const char *prefi
 	if ((sfd = open_write_dir(path, sizeof(path), prefix)) < 0)
 		return sfd;
 
-	tmp_name = alloca(strlen(name)+5);
+	tmp_name = __builtin_alloca(strlen(name)+5);
 	sprintf(tmp_name, "%s.tmp", name);
 	if ((fd = openat(sfd, tmp_name,  O_CLOEXEC | O_CREAT | O_WRONLY | O_TRUNC, 0600)) < 0) {
 		res = -errno;
@@ -472,7 +470,7 @@ SPA_EXPORT
 int pw_conf_load_conf(const char *prefix, const char *name, struct pw_properties *conf)
 {
 	char path[PATH_MAX];
-	char fname[PATH_MAX + 256];
+	char fname[PATH_MAX + 1024];
 	int i, res, level = 0;
 	spa_autoptr(pw_properties) override = NULL;
 	const char *dname;
