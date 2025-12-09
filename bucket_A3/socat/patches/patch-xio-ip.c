--- xio-ip.c.orig	2025-12-08 07:44:32 UTC
+++ xio-ip.c
@@ -888,7 +888,7 @@ int xioresolve(const char *node, const c
    }
    if (res == NULL) {
       Error3("xioresolve(node=\"%s\", pf=%d, ...): %s",
-	     node?node:"NULL", pf, gai_strerror(EAI_NODATA));
+	     node?node:"NULL", pf, gai_strerror(EAI_NONAME));
       xiofreeaddrinfo(res);
       return STAT_NORETRY;
    }
