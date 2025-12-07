--- src/corelib/thread/qmutex.cpp.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/thread/qmutex.cpp
@@ -843,7 +843,7 @@ void QBasicMutex::unlockInternal(void *c
     Q_ASSERT(copy); //we must be locked
     Q_ASSERT(copy != dummyLocked()); // testAndSetRelease(dummyLocked(), 0) failed
 
-#  if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_WIN)
+#  if (defined(Q_OS_FREEBSD) && !defined(__DragonFly__)) || defined(Q_OS_LINUX) || defined(Q_OS_WIN)
     // these platforms always have futex and have never called this function
     // from inline code
     Q_UNREACHABLE();
