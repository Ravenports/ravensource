--- storage/innobase/include/trx0trx.h.orig	2025-01-29 10:22:21 UTC
+++ storage/innobase/include/trx0trx.h
@@ -605,10 +605,8 @@ private:
   /** mutex protecting state and some of lock
   (some are protected by lock_sys.latch) */
   srw_spin_mutex mutex;
-#ifdef UNIV_DEBUG
   /** The owner of mutex (0 if none); protected by mutex */
   std::atomic<pthread_t> mutex_owner{0};
-#endif /* UNIV_DEBUG */
 public:
   void mutex_init() { mutex.init(); }
   void mutex_destroy() { mutex.destroy(); }
