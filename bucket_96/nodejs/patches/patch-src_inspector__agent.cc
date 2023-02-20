--- src/inspector_agent.cc.orig	2023-02-16 16:14:46 UTC
+++ src/inspector_agent.cc
@@ -98,7 +98,7 @@ static int StartDebugSignalHandler() {
   CHECK_EQ(0, uv_sem_init(&start_io_thread_semaphore, 0));
   pthread_attr_t attr;
   CHECK_EQ(0, pthread_attr_init(&attr));
-#if defined(PTHREAD_STACK_MIN) && !defined(__FreeBSD__)
+#if defined(PTHREAD_STACK_MIN) && !defined(__FreeBSD__) && !defined(__NetBSD__)
   // PTHREAD_STACK_MIN is 2 KiB with musl libc, which is too small to safely
   // receive signals. PTHREAD_STACK_MIN + MINSIGSTKSZ is 8 KiB on arm64, which
   // is the musl architecture with the biggest MINSIGSTKSZ so let's use that
