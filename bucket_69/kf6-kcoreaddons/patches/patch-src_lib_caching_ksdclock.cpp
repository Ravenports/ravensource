NetBSD does not support _POSIX_TIMEOUTS but kcoreaddons has a bug in this
configuration.  This patch should be pushed upstream.

--- src/lib/caching/ksdclock.cpp.orig	2024-04-05 10:55:37 UTC
+++ src/lib/caching/ksdclock.cpp
@@ -57,7 +57,9 @@ SharedLockId findBestSharedLock()
         sem_t tempSemaphore;
         std::unique_ptr<KSDCLock> tempLock;
         if (timeoutsSupported) {
+#ifdef KSDC_TIMEOUTS_SUPPORTED
             tempLock = std::make_unique<semaphoreTimedLock>(tempSemaphore);
+#endif
         } else {
             tempLock = std::make_unique<semaphoreLock>(tempSemaphore);
         }
