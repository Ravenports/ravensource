--- src/pipewire/mem.c.orig	2025-03-14 10:07:06 UTC
+++ src/pipewire/mem.c
@@ -27,6 +27,7 @@ PW_LOG_TOPIC_EXTERN(log_mem);
 #define PW_LOG_TOPIC_DEFAULT log_mem
 
 #if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__) \
+       && !defined(__DragonFly__) && !defined(__NetBSD__) \
        && !defined(HAVE_MEMFD_CREATE)
 /*
  * No glibc wrappers exist for memfd_create(2), so provide our own.
@@ -44,7 +45,7 @@ static inline int memfd_create(const cha
 #define HAVE_MEMFD_CREATE 1
 #endif
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__DragonFly__) || defined(__NetBSD__)
 #define MAP_LOCKED 0
 #endif
 
