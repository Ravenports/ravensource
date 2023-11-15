--- filan.c.orig	2023-11-13 19:31:08 UTC
+++ filan.c
@@ -939,6 +939,7 @@ int tcpan(int fd, FILE *outfile) {
 #if WITH_TCP && defined(TCP_INFO)
 
 int tcpan2(int fd, FILE *outfile) {
+# ifdef TCP_INFO
    struct tcp_info tcpinfo;
    socklen_t tcpinfolen = sizeof(tcpinfo);
    int result;
@@ -966,6 +967,9 @@ int tcpan2(int fd, FILE *outfile) {
 #endif
 
    return 0;
+# else
+   return -1;
+# endif
 }
 
 #endif /* WITH_TCP */
