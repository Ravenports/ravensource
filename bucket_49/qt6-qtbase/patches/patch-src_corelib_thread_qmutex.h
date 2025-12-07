--- src/corelib/thread/qmutex.h.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/thread/qmutex.h
@@ -25,7 +25,7 @@ class QT6_ONLY(Q_CORE_EXPORT) QBasicMute
     Q_DISABLE_COPY_MOVE(QBasicMutex)
 protected:
     static constexpr bool FutexAlwaysAvailable =
-#if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_WIN) // these platforms use futex
+#if (defined(Q_OS_FREEBSD) && !defined(__DragonFly__)) || defined(Q_OS_LINUX) || defined(Q_OS_WIN) // these platforms use futex
             true
 #else
             false
