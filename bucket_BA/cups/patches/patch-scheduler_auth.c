--- scheduler/auth.c.orig	2023-06-13 13:00:48 UTC
+++ scheduler/auth.c
@@ -449,7 +449,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
     peersize = sizeof(peercred);
 
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
     if (getsockopt(httpGetFd(con->http), 0, LOCAL_PEERCRED, &peercred, &peersize))
 #  else
     if (getsockopt(httpGetFd(con->http), SOL_SOCKET, SO_PEERCRED, &peercred, &peersize))
@@ -840,7 +840,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
       peersize = sizeof(peercred);
 
-#    ifdef __APPLE__
+#    if defined(__APPLE__) || defined(__FreeBSD__)
       if (getsockopt(httpGetFd(con->http), 0, LOCAL_PEERCRED, &peercred, &peersize))
 #    else
       if (getsockopt(httpGetFd(con->http), SOL_SOCKET, SO_PEERCRED, &peercred,
