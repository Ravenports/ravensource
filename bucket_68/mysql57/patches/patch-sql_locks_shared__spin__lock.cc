--- sql/locks/shared_spin_lock.cc.orig	2020-12-10 03:01:55 UTC
+++ sql/locks/shared_spin_lock.cc
@@ -239,7 +239,11 @@ lock::Shared_spin_lock &lock::Shared_spi
   {
     this->spin_exclusive_lock();
   }
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
+#else
   my_atomic_store64(&this->m_exclusive_owner, self);
+#endif
   return (*this);
 }
 
