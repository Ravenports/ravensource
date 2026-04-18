--- erts/emulator/nifs/common/prim_socket_nif.c.orig	2026-03-12 15:54:38 UTC
+++ erts/emulator/nifs/common/prim_socket_nif.c
@@ -67,14 +67,17 @@ ERL_NIF_INIT(prim_socket, esock_funcs, o
 
 #else
 
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
 
 #include <stdio.h>
