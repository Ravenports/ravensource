--- sql/resourcegroups/platform/thread_attrs_api_solaris.cc.orig	2025-12-15 13:32:53 UTC
+++ sql/resourcegroups/platform/thread_attrs_api_solaris.cc
@@ -33,112 +33,41 @@
 
 namespace resourcegroups {
 namespace platform {
-bool is_platform_supported() { return true; }
+bool is_platform_supported() { return false; }
 
 bool bind_to_cpu(cpu_id_t cpu_id) {
-  if (processor_bind(P_LWPID, P_MYID, static_cast<processorid_t>(cpu_id),
-                     nullptr) == -1) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_BIND_TO_CPUID_FAILED,
-           cpu_id, my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 bool bind_to_cpu(cpu_id_t cpu_id, my_thread_os_id_t thread_id) {
-  if (processor_bind(P_LWPID, thread_id, static_cast<processorid_t>(cpu_id),
-                     nullptr) == -1) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_BIND_TO_THREAD_FAILED,
-           thread_id, cpu_id, my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 bool bind_to_cpus(const std::vector<cpu_id_t> &cpu_ids) {
-  if (cpu_ids.empty()) return false;
-
-  procset_t ps;
-  uint_t nids = cpu_ids.size();
-  id_t *ids = reinterpret_cast<id_t *>(const_cast<unsigned *>(cpu_ids.data()));
-  uint32_t flags = PA_TYPE_CPU | PA_AFF_STRONG;
-
-  setprocset(&ps, POP_AND, P_PID, P_MYID, P_LWPID, my_thread_os_id());
-  if (processor_affinity(&ps, &nids, ids, &flags) != 0) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_AFFINITY_FAILED,
-           "bind_to_cpus", my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 bool bind_to_cpus(const std::vector<cpu_id_t> &cpu_ids,
                   my_thread_os_id_t thread_id) {
-  procset_t ps;
-  uint_t nids = cpu_ids.size();
-  id_t *ids = reinterpret_cast<id_t *>(const_cast<unsigned *>(cpu_ids.data()));
-  uint32_t flags = PA_TYPE_CPU | PA_AFF_STRONG;
-
-  setprocset(&ps, POP_AND, P_PID, P_MYID, P_LWPID,
-             static_cast<id_t>(thread_id));
-
-  if (processor_affinity(&ps, &nids, ids, &flags) != 0) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_AFFINITY_FAILED,
-           "bind_to_cpus", my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 bool unbind_thread() {
-  procset_t ps;
-  uint32_t flags = PA_CLEAR;
-
-  setprocset(&ps, POP_AND, P_PID, P_MYID, P_LWPID, my_thread_os_id());
-
-  if (processor_affinity(&ps, nullptr, nullptr, &flags) != 0) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_AFFINITY_FAILED,
-           "unbind_thread", my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 bool unbind_thread(my_thread_os_id_t thread_id) {
-  procset_t ps;
-  uint32_t flags = PA_CLEAR;
-
-  setprocset(&ps, POP_AND, P_PID, P_MYID, P_LWPID, thread_id);
-
-  if (processor_affinity(&ps, nullptr, nullptr, &flags) != 0) {
-    char errbuf[MYSQL_ERRMSG_SIZE];
-    LogErr(ERROR_LEVEL, ER_RES_GRP_SOLARIS_PROCESSOR_AFFINITY_FAILED,
-           "unbind_thread", my_errno(),
-           my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
-    return true;
-  }
-  return false;
+  return true;
 }
 
 int thread_priority() { return getpriority(PRIO_PROCESS, my_thread_os_id()); }
 
 int thread_priority(my_thread_os_id_t thread_id) {
-  DBUG_TRACE;
-  return getpriority(PRIO_PROCESS, thread_id);
+  return 0;
 }
 
 bool set_thread_priority(int priority) {
-  return set_thread_priority(priority, my_thread_os_id());
+  return false;
 }
 
 bool set_thread_priority(int, my_thread_os_id_t) {
