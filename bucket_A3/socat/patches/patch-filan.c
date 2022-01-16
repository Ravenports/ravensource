--- filan.c.orig	2022-01-08 20:59:57 UTC
+++ filan.c
@@ -907,6 +907,7 @@ int tcpan(int fd, FILE *outfile) {
 #if WITH_TCP && defined(TCP_INFO)
 
 int tcpan2(int fd, FILE *outfile) {
+# ifdef TCP_INFO
    struct tcp_info tcpinfo;
    socklen_t tcpinfolen = sizeof(tcpinfo);
    int result;
@@ -932,6 +933,9 @@ int tcpan2(int fd, FILE *outfile) {
    // fprintf(outfile, "%s={%u}\t", "TCPI_", tcpinfo.tcpi_);
 
    return 0;
+# else
+   return -1;
+# endif
 }
 
 #endif /* WITH_TCP */
