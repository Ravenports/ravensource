--- filan.c.orig	2022-10-30 15:21:47 UTC
+++ filan.c
@@ -932,6 +932,7 @@ int tcpan(int fd, FILE *outfile) {
 #if WITH_TCP && defined(TCP_INFO)
 
 int tcpan2(int fd, FILE *outfile) {
+# ifdef TCP_INFO
    struct tcp_info tcpinfo;
    socklen_t tcpinfolen = sizeof(tcpinfo);
    int result;
@@ -957,6 +958,9 @@ int tcpan2(int fd, FILE *outfile) {
    // fprintf(outfile, "%s={%u}\t", "TCPI_", tcpinfo.tcpi_);
 
    return 0;
+# else
+   return -1;
+# endif
 }
 
 #endif /* WITH_TCP */
