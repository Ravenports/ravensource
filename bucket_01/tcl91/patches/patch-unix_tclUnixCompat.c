--- unix/tclUnixCompat.c.orig	2026-09-23 18:52:24 UTC
+++ unix/tclUnixCompat.c
@@ -102,7 +102,7 @@ static Tcl_Mutex compatLock;
 static int		CopyGrp(struct group *tgtPtr, char *buf, int buflen);
 #endif
 
-#if !defined(HAVE_GETPWNAM_R_5) && !defined(HAVE_GETPWNAM_R_4)
+#if !defined(HAVE_GETPWNAM_R_5) && !defined(HAVE_GETPWNAM_R_4) || defined(__sun)
 #define NEED_COPYPWD 1
 static int		CopyPwd(struct passwd *tgtPtr, char *buf, int buflen);
 #endif
