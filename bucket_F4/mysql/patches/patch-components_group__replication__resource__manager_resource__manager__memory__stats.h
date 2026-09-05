--- components/group_replication_resource_manager/resource_manager_memory_stats.h.orig	2026-07-10 11:18:36 UTC
+++ components/group_replication_resource_manager/resource_manager_memory_stats.h
@@ -5,6 +5,7 @@
 #ifndef GR_RESOURCE_MANAGER_MEMORY_STATS
 #define GR_RESOURCE_MANAGER_MEMORY_STATS
 
+#include <ctime>
 #include <cerrno>
 #include <cstdint>
 #include <cstring>
