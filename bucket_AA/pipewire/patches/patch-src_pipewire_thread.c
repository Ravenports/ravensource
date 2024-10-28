--- src/pipewire/thread.c.orig	2024-10-23 07:44:10 UTC
+++ src/pipewire/thread.c
@@ -28,7 +28,11 @@ do {									\
 	}								\
 } while(false);
 
+#if defined(__MidnightBSD__)
+static int parse_affinity(const char *affinity, cpuset_t *set)
+#else
 static int parse_affinity(const char *affinity, cpu_set_t *set)
+#endif
 {
 	struct spa_json it[2];
 	int v;
@@ -80,7 +84,11 @@ int pthread_setname_np(pthread_t thread,
 
 static int thread_setaffinity(pthread_t thread, const char *affinity)
 {
+#if defined(__MidnightBSD__)
+	cpuset_t set;
+#else
 	cpu_set_t set;
+#endif
 	parse_affinity(affinity, &set);
 	return -pthread_setaffinity_np(thread, sizeof(set), &set);
 }
