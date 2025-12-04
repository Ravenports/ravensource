--- scheduler/auth.c.orig	2025-11-27 15:21:54 UTC
+++ scheduler/auth.c
@@ -455,7 +455,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
     peersize = sizeof(peercred);
 
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
     if (getsockopt(httpGetFd(con->http), 0, LOCAL_PEERCRED, &peercred, &peersize))
 #  else
     if (getsockopt(httpGetFd(con->http), SOL_SOCKET, SO_PEERCRED, &peercred, &peersize))
@@ -591,7 +591,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
       strlcpy(data.password, password, sizeof(data.password));
 
 #  ifdef __sun
-      pamdata.conv        = (int (*)(int, struct pam_message **,
+      pamdata.conv        = (int (*)(int, const struct pam_message **,
 				     struct pam_response **,
 				     void *))pam_func;
 #  else
@@ -865,7 +865,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
       peersize = sizeof(peercred);
 
-#    ifdef __APPLE__
+#    if defined(__APPLE__) || defined(__FreeBSD__)
       if (getsockopt(httpGetFd(con->http), 0, LOCAL_PEERCRED, &peercred, &peersize))
 #    else
       if (getsockopt(httpGetFd(con->http), SOL_SOCKET, SO_PEERCRED, &peercred,
