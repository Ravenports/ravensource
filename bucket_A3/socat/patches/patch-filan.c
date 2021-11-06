--- filan.c.orig	2021-10-31 18:06:09 UTC
+++ filan.c
@@ -905,6 +905,7 @@ int tcpan(int fd, FILE *outfile) {
 #if WITH_TCP
 
 int tcpan2(int fd, FILE *outfile) {
+# ifdef TCP_INFO
    struct tcp_info tcpinfo;
    socklen_t tcpinfolen = sizeof(tcpinfo);
    int result;
@@ -930,6 +931,9 @@ int tcpan2(int fd, FILE *outfile) {
    // fprintf(outfile, "%s={%u}\t", "TCPI_", tcpinfo.tcpi_);
 
    return 0;
+# else
+   return -1;
+# endif
 }
 
 #endif /* WITH_TCP */
