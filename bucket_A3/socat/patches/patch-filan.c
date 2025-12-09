--- filan.c.orig	2025-12-08 07:44:32 UTC
+++ filan.c
@@ -989,6 +989,7 @@ int tcpan(int fd, FILE *outfile) {
 #if WITH_TCP && defined(TCP_INFO)
 
 int tcpan2(int fd, FILE *outfile) {
+# ifdef TCP_INFO
    struct tcp_info tcpinfo;
    socklen_t tcpinfolen = sizeof(tcpinfo);
    int result;
@@ -1016,6 +1017,9 @@ int tcpan2(int fd, FILE *outfile) {
 #endif
 
    return 0;
+# else
+   return -1;
+# endif
 }
 
 #endif /* WITH_TCP */
