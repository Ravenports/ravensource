--- storage/innobase/include/trx0trx.h.orig	2025-11-13 17:00:50 UTC
+++ storage/innobase/include/trx0trx.h
@@ -673,14 +673,10 @@ public:
   {
     ut_ad(!mutex_is_owner());
     mutex.wr_lock();
-    assert(!mutex_owner.exchange(pthread_self(),
-                                 std::memory_order_relaxed));
   }
   /** Release the mutex */
   void mutex_unlock()
   {
-    assert(mutex_owner.exchange(0, std::memory_order_relaxed) ==
-           pthread_self());
     mutex.wr_unlock();
   }
 #ifndef SUX_LOCK_GENERIC
