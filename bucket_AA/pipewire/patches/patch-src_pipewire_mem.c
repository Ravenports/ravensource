--- src/pipewire/mem.c.orig	2024-09-27 10:02:20 UTC
+++ src/pipewire/mem.c
@@ -26,6 +26,7 @@ PW_LOG_TOPIC_EXTERN(log_mem);
 #define PW_LOG_TOPIC_DEFAULT log_mem
 
 #if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__) \
+       && !defined(__DragonFly__) \
        && !defined(HAVE_MEMFD_CREATE)
 /*
  * No glibc wrappers exist for memfd_create(2), so provide our own.
@@ -43,7 +44,7 @@ static inline int memfd_create(const cha
 #define HAVE_MEMFD_CREATE 1
 #endif
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__DragonFly__)
 #define MAP_LOCKED 0
 #endif
 
@@ -556,7 +557,7 @@ struct pw_memblock * pw_mempool_alloc(st
 		pw_log_error("%p: Failed to create memfd: %m", pool);
 		goto error_free;
 	}
-#elif defined(__FreeBSD__) || defined(__MidnightBSD__)
+#elif defined(__FreeBSD__) || defined(__MidnightBSD__) || !defined(__DragonFly__)
 	b->this.fd = shm_open(SHM_ANON, O_CREAT | O_RDWR | O_CLOEXEC, 0);
 	if (b->this.fd == -1) {
 		res = -errno;
