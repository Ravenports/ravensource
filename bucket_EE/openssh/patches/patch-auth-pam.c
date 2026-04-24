--- auth-pam.c.orig	2026-04-02 08:09:03 UTC
+++ auth-pam.c
@@ -68,11 +68,7 @@
 #endif
 
 /* OpenGroup RFC86.0 and XSSO specify no "const" on arguments */
-#ifdef PAM_SUN_CODEBASE
-# define sshpam_const		/* Solaris, HP-UX, SunOS */
-#else
 # define sshpam_const	const	/* LinuxPAM, OpenPAM, AIX */
-#endif
 
 /* Ambiguity in spec: is it an array of pointers or a pointer to an array? */
 #ifdef PAM_SUN_CODEBASE
