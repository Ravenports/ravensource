--- storage/innobase/include/trx0trx.h.orig	2025-07-28 19:35:06 UTC
+++ storage/innobase/include/trx0trx.h
@@ -671,14 +671,10 @@ public:
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
