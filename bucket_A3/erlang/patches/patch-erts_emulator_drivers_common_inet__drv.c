--- erts/emulator/drivers/common/inet_drv.c.orig	2026-04-23 10:09:44 UTC
+++ erts/emulator/drivers/common/inet_drv.c
@@ -24,6 +24,10 @@
 #include "config.h"
 #endif
 
+#if defined(__sun)
+#define  _XPG4_2
+#define  __EXTENSIONS__
+#endif
 
 /* If we HAVE_SCTP_H and Solaris, we need to define the following in
  * order to get SCTP working:
@@ -31,8 +35,6 @@
 #if (defined(HAVE_SCTP_H) && defined(__sun) && defined(__SVR4))
 #define  SOLARIS10    1
 /* WARNING: This is not quite correct, it may also be Solaris 11! */
-#define  _XPG4_2
-#define  __EXTENSIONS__
 #endif
 
 #include <stdio.h>
@@ -14496,7 +14498,9 @@ static ErlDrvSSizeT packet_inet_ctl(ErlD
         switch(buf[2]) {
         case INET_PROTO_DEFAULT: protocol = 0; break;
         case INET_PROTO_UDP: protocol = IPPROTO_UDP; break;
+#ifdef HAVE_SCTP
         case INET_PROTO_SCTP: protocol = IPPROTO_SCTP; break;
+#endif
         default:
             return ctl_xerror(str_eprotonosupport, rbuf, rsize);
         }
