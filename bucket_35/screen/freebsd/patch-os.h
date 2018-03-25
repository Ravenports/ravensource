--- os.h.orig	2017-10-23 11:32:41 UTC
+++ os.h
@@ -250,9 +250,7 @@ extern int errno;
 #endif
 
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
-# if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -261,9 +259,6 @@ extern int errno;
 #  define setutent	setutxent
 #  define endutent	endutxent
 #  define ut_time	ut_xtime
-# else /* SVR4 */
-#  include <utmp.h>
-# endif /* SVR4 */
 # ifdef apollo
    /* 
     * We don't have GETUTENT, so we dig into utmp ourselves.
@@ -524,6 +519,6 @@ typedef struct fd_set { int fds_bits[1];
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
