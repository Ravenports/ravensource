--- posix.c.orig	2023-11-21 14:40:35 UTC
+++ posix.c
@@ -784,7 +784,7 @@ PHP_FUNCTION(posix_getgrnam)
 #if defined(ZTS) && defined(HAVE_GETGRNAM_R) && defined(_SC_GETGR_R_SIZE_MAX)
 	buflen = sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (buflen < 1) {
-		RETURN_FALSE;
+		buflen = 1024;
 	}
 	buf = emalloc(buflen);
 try_again:
@@ -840,7 +840,7 @@ PHP_FUNCTION(posix_getgrgid)
 
 	grbuflen = sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (grbuflen < 1) {
-		RETURN_FALSE;
+		grbuflen = 1024;
 	}
 
 	grbuf = emalloc(grbuflen);
@@ -914,7 +914,7 @@ PHP_FUNCTION(posix_getpwnam)
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWNAM_R)
 	buflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (buflen < 1) {
-		RETURN_FALSE;
+		buflen = 1024;
 	}
 	buf = emalloc(buflen);
 	pw = &pwbuf;
@@ -969,7 +969,7 @@ PHP_FUNCTION(posix_getpwuid)
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWUID_R)
 	pwbuflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (pwbuflen < 1) {
-		RETURN_FALSE;
+		pwbuflen = 1024;
 	}
 	pwbuf = emalloc(pwbuflen);
 
