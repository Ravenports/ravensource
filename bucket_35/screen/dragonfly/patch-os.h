--- os.h.orig	2017-10-23 11:32:41 UTC
+++ os.h
@@ -250,9 +250,8 @@ extern int errno;
 #endif
 
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
-# if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
+#  define UTMPFILE	_PATH_UTMPX
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -261,9 +260,6 @@ extern int errno;
 #  define setutent	setutxent
 #  define endutent	endutxent
 #  define ut_time	ut_xtime
-# else /* SVR4 */
-#  include <utmp.h>
-# endif /* SVR4 */
 # ifdef apollo
    /* 
     * We don't have GETUTENT, so we dig into utmp ourselves.
@@ -273,19 +269,6 @@ extern int errno;
     */
 #  define UTNOKEEP
 # endif /* apollo */
-
-# ifndef UTMPFILE
-#  ifdef UTMP_FILE
-#   define UTMPFILE	UTMP_FILE
-#  else
-#   ifdef _PATH_UTMP
-#    define UTMPFILE	_PATH_UTMP
-#   else
-#    define UTMPFILE	"/etc/utmp"
-#   endif /* _PATH_UTMP */
-#  endif
-# endif
-
 #endif /* UTMPOK || BUGGYGETLOGIN */
 
 #if !defined(UTMPOK) && defined(USRLIMIT)
