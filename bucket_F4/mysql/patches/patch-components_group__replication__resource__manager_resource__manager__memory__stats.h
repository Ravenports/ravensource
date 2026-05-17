--- components/group_replication_resource_manager/resource_manager_memory_stats.h.orig	2026-04-07 16:08:28.000000000 -0000
+++ components/group_replication_resource_manager/resource_manager_memory_stats.h
@@ -5,6 +5,7 @@
 #ifndef GR_RESOURCE_MANAGER_MEMORY_STATS
 #define GR_RESOURCE_MANAGER_MEMORY_STATS
 
+#include <ctime>
 #include <cerrno>
 #include <cstdint>
 #include <cstring>
