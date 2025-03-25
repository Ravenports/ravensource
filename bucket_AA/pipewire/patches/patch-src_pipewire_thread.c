--- src/pipewire/thread.c.orig	2025-03-14 10:07:06 UTC
+++ src/pipewire/thread.c
@@ -9,6 +9,9 @@
 #ifdef __FreeBSD__
 #include <pthread_np.h>
 #endif
+#ifdef __NetBSD__
+#include <sched.h>
+#endif
 
 #include <spa/utils/dict.h>
 #include <spa/utils/defs.h>
@@ -29,18 +32,31 @@ do {									\
 	}								\
 } while(false);
 
+#if defined(__MidnightBSD__) || defined(__NetBSD__)
+static int parse_affinity(const char *affinity, cpuset_t *set)
+#else
 static int parse_affinity(const char *affinity, cpu_set_t *set)
+#endif
 {
 	struct spa_json it[1];
 	int v;
 
+#if defined(__NetBSD__)
+	cpuset_zero(set);
+#else
 	CPU_ZERO(set);
+#endif
 	if (spa_json_begin_array_relax(&it[0], affinity, strlen(affinity)) <= 0)
 		return 0;
 
 	while (spa_json_get_int(&it[0], &v) > 0) {
+#if defined(__NetBSD__)
+		if (v >= 0 && v < (int)cpuset_size(set))
+			cpuset_set(v, set);
+#else
 		if (v >= 0 && v < CPU_SETSIZE)
 			CPU_SET(v, set);
+#endif
         }
 	return 0;
 }
@@ -80,9 +96,23 @@ int pthread_setname_np(pthread_t thread,
 
 static int thread_setaffinity(pthread_t thread, const char *affinity)
 {
+#if defined(__MidnightBSD__)
+	cpuset_t set;
+#elif defined(__NetBSD__)
+	cpuset_t *set = cpuset_create();
+#else
 	cpu_set_t set;
+#endif
+	int result;
+#if defined(__NetBSD__)
+	parse_affinity(affinity, set);
+	result = pthread_setaffinity_np(thread, cpuset_size(set), set);
+	cpuset_destroy(set);
+#else
 	parse_affinity(affinity, &set);
-	return -pthread_setaffinity_np(thread, sizeof(set), &set);
+	result = -pthread_setaffinity_np(thread, sizeof(set), &set);
+#endif
+	return result;
 }
 
 static struct spa_thread *impl_create(void *object,
@@ -113,7 +143,11 @@ static struct spa_thread *impl_create(vo
 	}
 	if (props) {
 		if ((str = spa_dict_lookup(props, SPA_KEY_THREAD_NAME)) != NULL &&
+#if defined(__NetBSD__)
+		    (err = pthread_setname_np(pt, "%s", (void *)str)) != 0)
+#else
 		    (err = pthread_setname_np(pt, str)) != 0)
+#endif
 			pw_log_warn("pthread_setname error: %s", strerror(err));
 		if ((str = spa_dict_lookup(props, SPA_KEY_THREAD_AFFINITY)) != NULL &&
 		    (err = thread_setaffinity(pt, str)) != 0)
