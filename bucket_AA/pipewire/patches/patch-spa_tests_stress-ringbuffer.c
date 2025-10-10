--- spa/tests/stress-ringbuffer.c.orig	2025-09-11 08:12:34 UTC
+++ spa/tests/stress-ringbuffer.c
@@ -19,6 +19,9 @@
 static int sched_getcpu(void) { return -1; };
 #endif
 #endif
+#if defined(__NetBSD__)
+static int sched_getcpu(void) { return -1; };
+#endif
 
 static struct spa_ringbuffer rb;
 static uint32_t size;
