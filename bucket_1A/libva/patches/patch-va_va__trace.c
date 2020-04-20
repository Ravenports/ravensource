--- va/va_trace.c.orig	2020-04-18 15:31:01 UTC
+++ va/va_trace.c
@@ -50,6 +50,9 @@
 #include <sys/stat.h>
 #include <sys/syscall.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 #include <unistd.h>
 #include <sys/time.h>
 #include <errno.h>
@@ -288,7 +291,15 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#elif defined __sun__
+    pid_t thd_id = pthread_self();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -493,6 +504,18 @@ static int get_valid_ctx_idx(
     return idx;
 }
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+#endif
+
 static void FILE_NAME_SUFFIX(
     char *env_value,
     int max_size,
@@ -666,7 +689,15 @@ static struct trace_log_file *start_trac
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#elif defined __sun__
+    pid_t thd_id = pthread_self();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -705,7 +736,15 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#elif defined __sun__
+    pid_t thd_id = pthread_self();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1231,7 +1270,15 @@ static void internal_TraceUpdateContext
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#elif defined __sun__
+    pid_t thd_id = pthread_self();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;
