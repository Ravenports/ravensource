--- storage/rocksdb/ha_rocksdb.cc.orig	2025-07-31 19:06:53 UTC
+++ storage/rocksdb/ha_rocksdb.cc
@@ -262,7 +262,7 @@ Rdb_cf_manager cf_manager;
 Rdb_ddl_manager ddl_manager;
 Rdb_binlog_manager binlog_manager;
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 Rdb_io_watchdog *io_watchdog = nullptr;
 #endif
 /**
@@ -841,7 +841,7 @@ static void rocksdb_set_io_write_timeout
     void *const var_ptr MY_ATTRIBUTE((__unused__)), const void *const save) {
   DBUG_ASSERT(save != nullptr);
   DBUG_ASSERT(rdb != nullptr);
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
   DBUG_ASSERT(io_watchdog != nullptr);
 #endif
 
@@ -850,7 +850,7 @@ static void rocksdb_set_io_write_timeout
   const uint32_t new_val = *static_cast<const uint32_t *>(save);
 
   rocksdb_io_write_timeout_secs = new_val;
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
   io_watchdog->reset_timeout(rocksdb_io_write_timeout_secs);
 #endif
   RDB_MUTEX_UNLOCK_CHECK(rdb_sysvars_mutex);
@@ -5778,7 +5778,7 @@ static int rocksdb_init_func(void *const
     directories.push_back(myrocks::rocksdb_wal_dir);
   }
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
   io_watchdog = new Rdb_io_watchdog(std::move(directories));
   io_watchdog->reset_timeout(rocksdb_io_write_timeout_secs);
 #endif
@@ -5877,7 +5877,7 @@ static int rocksdb_done_func(void *const
   delete commit_latency_stats;
   commit_latency_stats = nullptr;
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
   delete io_watchdog;
   io_watchdog = nullptr;
 #endif
