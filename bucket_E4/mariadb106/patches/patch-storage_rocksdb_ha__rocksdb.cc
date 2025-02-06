--- storage/rocksdb/ha_rocksdb.cc.orig	2025-01-29 10:22:22 UTC
+++ storage/rocksdb/ha_rocksdb.cc
@@ -266,7 +266,7 @@ Rdb_cf_manager cf_manager;
 Rdb_ddl_manager ddl_manager;
 Rdb_binlog_manager binlog_manager;
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if defined(HAVE_TIMER_DELETE) && !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
 Rdb_io_watchdog *io_watchdog = nullptr;
 #endif
 /**
@@ -850,7 +850,7 @@ static void rocksdb_set_io_write_timeout
     void *const var_ptr MY_ATTRIBUTE((__unused__)), const void *const save) {
   DBUG_ASSERT(save != nullptr);
   DBUG_ASSERT(rdb != nullptr);
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if defined(HAVE_TIMER_DELETE) && !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
   DBUG_ASSERT(io_watchdog != nullptr);
 #endif
 
@@ -859,7 +859,7 @@ static void rocksdb_set_io_write_timeout
   const uint32_t new_val = *static_cast<const uint32_t *>(save);
 
   rocksdb_io_write_timeout_secs = new_val;
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if defined(HAVE_TIMER_DELETE) && !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
   io_watchdog->reset_timeout(rocksdb_io_write_timeout_secs);
 #endif
   RDB_MUTEX_UNLOCK_CHECK(rdb_sysvars_mutex);
@@ -5798,7 +5798,7 @@ static int rocksdb_init_func(void *const
     directories.push_back(myrocks::rocksdb_wal_dir);
   }
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if defined(HAVE_TIMER_DELETE) && !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
   io_watchdog = new Rdb_io_watchdog(std::move(directories));
   io_watchdog->reset_timeout(rocksdb_io_write_timeout_secs);
 #endif
@@ -5905,7 +5905,7 @@ static int rocksdb_done_func(void *const
   delete commit_latency_stats;
   commit_latency_stats = nullptr;
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
+#if defined(HAVE_TIMER_DELETE) && !defined(_WIN32) && !defined(__APPLE__) && !defined(__OpenBSD__)
   delete io_watchdog;
   io_watchdog = nullptr;
 #endif
