This definitely breaks the build.  Keep until it is sorted

--- deps/hiredis/net.c.orig	2026-02-10 14:08:46 UTC
+++ deps/hiredis/net.c
@@ -204,6 +204,27 @@ int redisKeepAlive(redisContext *c, int
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
+#else
+#if !defined(__sun) && defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTVL) && \
+    defined(TCP_KEEPCNT)
+    val = interval;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+ 
+    val = interval/3;
+    if (val == 0) val = 1;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+
+    val = 3;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
 #endif
 #endif
 #else
