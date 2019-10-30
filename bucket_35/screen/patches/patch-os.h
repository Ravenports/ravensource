--- os.h.orig	2019-10-01 22:08:00 UTC
+++ os.h
@@ -250,9 +250,11 @@ extern int errno;
 #endif
 
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
-# if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
+# if (defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
+#  ifdef UTMPX_FILE /* GNU extension */
+#   define UTMPFILE	UTMPX_FILE
+#  endif
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -507,7 +509,7 @@ typedef struct fd_set { int fds_bits[1];
  */
 
 #ifndef TERMCAP_BUFSIZE
-# define TERMCAP_BUFSIZE 2048
+# define TERMCAP_BUFSIZE 1023
 #endif
 
 #ifndef MAXPATHLEN
@@ -524,6 +526,6 @@ typedef struct fd_set { int fds_bits[1];
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
