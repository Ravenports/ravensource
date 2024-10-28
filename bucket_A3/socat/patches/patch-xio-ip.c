--- xio-ip.c.orig	2024-08-24 16:06:11 UTC
+++ xio-ip.c
@@ -799,7 +799,7 @@ int xioresolve(const char *node, const c
    }
    if (res == NULL) {
       Error3("xioresolve(node=\"%s\", pf=%d, ...): %s",
-	     node?node:"NULL", pf, gai_strerror(EAI_NODATA));
+	     node?node:"NULL", pf, gai_strerror(EAI_NONAME));
       xiofreeaddrinfo(res);
       return STAT_NORETRY;
    }
