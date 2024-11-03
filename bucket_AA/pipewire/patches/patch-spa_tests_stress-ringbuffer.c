--- spa/tests/stress-ringbuffer.c.orig	2024-10-23 07:44:10 UTC
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
