--- sql/resourcegroups/platform/thread_attrs_api_apple.cc.orig	2025-07-09 08:45:01 UTC
+++ sql/resourcegroups/platform/thread_attrs_api_apple.cc
@@ -86,7 +86,11 @@ bool set_thread_priority(int, my_thread_
 uint32_t num_vcpus_using_affinity() { return 0; }
 
 uint32_t num_vcpus_using_config() {
+#ifdef __APPLE__
   int name[2] = {CTL_HW, HW_AVAILCPU};
+#else
+  int name[2] = {CTL_HW, HW_NCPU};
+#endif
   int ncpu;
 
   size_t size = sizeof(ncpu);
