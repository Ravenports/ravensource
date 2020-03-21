--- util.c.orig	2020-03-17 10:00:17 UTC
+++ util.c
@@ -1167,20 +1167,20 @@ error(const char *format, ...)
 }
 
 #ifdef HAVE_CPUSET_T
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 int number_of_cpus(void)
 {
 	return (int)sysconf(_SC_NPROCESSORS_CONF);
 }
 #endif
-#if __linux__
+#if defined(__linux__) || defined(__DragonFly__)
 int set_cpu_affinity(cpuset_t *set)
 {
 	assert(set != NULL);
 	return sched_setaffinity(getpid(), sizeof(*set), set);
 }
 #endif
-#if __FreeBSD__
+#if defined(__FreeBSD__)
 int set_cpu_affinity(cpuset_t *set)
 {
 	assert(set != NULL);
