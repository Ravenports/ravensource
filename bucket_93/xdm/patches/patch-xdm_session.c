--- xdm/session.c.orig	2022-12-03 21:38:28 UTC
+++ xdm/session.c
@@ -590,6 +590,7 @@ StartClient (
     pid_t	pid;
 #ifdef HAVE_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -674,6 +675,8 @@ StartClient (
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+	/* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -681,6 +684,7 @@ StartClient (
 			  name, _SysErrorMsg (errno));
 		return (0);
 	    }
+	    verify->userEnviron = environ;
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed: %s\n",
