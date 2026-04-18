--- erts/emulator/nifs/unix/unix_socket_syncio.c.orig	2026-03-12 15:54:38 UTC
+++ erts/emulator/nifs/unix/unix_socket_syncio.c
@@ -33,14 +33,17 @@
 
 #ifdef ESOCK_ENABLE
 
+#if defined(__sun)
+#define _XPG4_2
+#define __EXTENSIONS__
+#endif
+
 /* If we HAVE_SCTP_H and Solaris, we need to define the following in
  * order to get SCTP working:
  */
 #if (defined(HAVE_SCTP_H) && defined(__sun) && defined(__SVR4))
 #define SOLARIS10    1
 /* WARNING: This is not quite correct, it may also be Solaris 11! */
-#define _XPG4_2
-#define __EXTENSIONS__
 #endif
 
 #ifdef HAVE_SENDFILE
