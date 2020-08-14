--- src/main.c.orig	2018-08-07 06:43:51 UTC
+++ src/main.c
@@ -19,7 +19,7 @@
 #include <pthread.h>
 #endif
 
-#if defined(HAVE_PTHREAD_SETAFFINITY_NP) && defined(__FreeBSD__)
+#if defined(HAVE_PTHREAD_SETAFFINITY_NP) && (defined(__FreeBSD__) || defined(__DragonFly__))
 #include <pthread_np.h>
 #endif
 
@@ -156,7 +156,7 @@ int main(int argc, char **argv) {
             if (opts.use_thread_affinity) {
 #ifdef __linux__
                 cpu_set_t cpu_set;
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
                 cpuset_t cpu_set;
 #endif
                 CPU_ZERO(&cpu_set);
