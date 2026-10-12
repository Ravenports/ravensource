--- storage/innobase/include/trx0trx.h.orig	2026-09-10 13:53:25 UTC
+++ storage/innobase/include/trx0trx.h
@@ -661,14 +661,10 @@ public:
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
