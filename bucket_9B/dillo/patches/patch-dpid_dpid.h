--- dpid/dpid.h.orig	2015-06-10 21:34:22 UTC
+++ dpid/dpid.h
@@ -25,10 +25,9 @@
 
 /*! \TODO: Should read this from dillorc */
 #define SRS_NAME "dpid.srs"
-char *srs_name;
 
 /*! dpid's service request socket file descriptor */
-int srs_fd;
+extern int srs_fd;
 
 /*! plugin state information
  */
@@ -49,19 +48,19 @@ struct service {
 };
 
 /*! Number of available plugins */
-int numdpis;
+extern int numdpis;
 
 /*! Number of sockets being watched */
-int numsocks;
+extern int numsocks;
 
 /*! State information for each plugin. */
-struct dp *dpi_attr_list;
+extern struct dp *dpi_attr_list;
 
 /*! service served for each plugin  */
-Dlist *services_list;
+extern Dlist *services_list;
 
 /*! Set of sockets watched for connections */
-fd_set sock_set;
+extern fd_set sock_set;
 
 /*! Set to 1 by the SIGCHLD handler dpi_sigchld */
 extern volatile sig_atomic_t caught_sigchld;
