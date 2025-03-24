--- xdm/session.c.orig	2025-03-09 01:13:49 UTC
+++ xdm/session.c
@@ -583,6 +583,7 @@ StartClient (
     pid_t	pid;
 #ifdef HAVE_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -665,6 +666,8 @@ StartClient (
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+	/* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -672,6 +675,7 @@ StartClient (
 			  name, _SysErrorMsg (errno));
 		return (0);
 	    }
+	    verify->userEnviron = environ;
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed: %s\n",
