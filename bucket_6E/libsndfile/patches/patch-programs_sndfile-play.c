--- programs/sndfile-play.c.orig	2023-08-13 08:53:51 UTC
+++ programs/sndfile-play.c
@@ -64,7 +64,7 @@
 #elif HAVE_SNDIO_H
 	#include <sndio.h>
 
-#elif (defined (sun) && defined (unix)) || defined(__NetBSD__)
+#elif defined(__NetBSD__)
 	#include <fcntl.h>
 	#include <sys/ioctl.h>
 	#include <sys/audioio.h>
@@ -729,7 +729,7 @@ sndio_play (int argc, char *argv [])
 **	Solaris.
 */
 
-#if (defined (sun) && defined (unix)) || defined(__NetBSD__)
+#if defined(__NetBSD__)
 
 static void
 solaris_play (int argc, char *argv [])
@@ -845,7 +845,7 @@ main (int argc, char *argv [])
 	opensoundsys_play (argc, argv) ;
 #elif HAVE_SNDIO_H
 	sndio_play (argc, argv) ;
-#elif (defined (sun) && defined (unix)) || defined(__NetBSD__)
+#elif defined(__NetBSD__)
 	solaris_play (argc, argv) ;
 #elif (OS_IS_WIN32 == 1)
 	win32_play (argc, argv) ;
