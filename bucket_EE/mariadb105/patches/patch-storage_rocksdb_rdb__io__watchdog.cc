If timer_t is an integer type, setting it to nullptr fails.

--- storage/rocksdb/rdb_io_watchdog.cc.orig	2025-01-28 18:36:06 UTC
+++ storage/rocksdb/rdb_io_watchdog.cc
@@ -111,7 +111,11 @@ void Rdb_io_watchdog::io_check_callback(
     sql_print_warning("Deleting the watchdog I/O timer failed with %d.", errno);
   }
 
+#ifdef __NetBSD__
+  m_io_check_watchdog_timer = 0;
+#else
   m_io_check_watchdog_timer = nullptr;
+#endif
 
   RDB_MUTEX_UNLOCK_CHECK(m_reset_mutex);
 }
