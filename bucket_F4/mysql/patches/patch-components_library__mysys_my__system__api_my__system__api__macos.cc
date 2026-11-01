--- components/library_mysys/my_system_api/my_system_api_macos.cc.orig	2026-10-06 06:57:52 UTC
+++ components/library_mysys/my_system_api/my_system_api_macos.cc
@@ -36,7 +36,11 @@
 uint32_t num_vcpus_using_affinity() { return 0; }
 
 uint32_t num_vcpus_using_config() {
+#ifdef __APPLE__
   int name[2] = {CTL_HW, HW_AVAILCPU};
+#else
+  int name[2] = {CTL_HW, HW_NCPU};
+#endif
   int ncpu;
 
   size_t size = sizeof(ncpu);
