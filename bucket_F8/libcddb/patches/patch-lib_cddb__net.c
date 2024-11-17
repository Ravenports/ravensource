--- lib/cddb_net.c.orig	2009-03-01 03:28:07 UTC
+++ lib/cddb_net.c
@@ -305,7 +305,7 @@ int timeout_connect(int sockfd, const st
             int rv;
             fd_set wfds;
             struct timeval tv;
-            size_t l;
+            socklen_t l;
 
             /* set up select time out */
             tv.tv_sec = timeout;
