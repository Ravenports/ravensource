--- dpid/dpid.c.orig	2015-06-10 21:34:22 UTC
+++ dpid/dpid.c
@@ -38,6 +38,13 @@
 
 #define QUEUE 5
 
+int srs_fd;
+int numdpis;
+int numsocks;
+struct dp *dpi_attr_list;
+Dlist *services_list;
+fd_set sock_set;
+
 volatile sig_atomic_t caught_sigchld = 0;
 char *SharedKey = NULL;
 
