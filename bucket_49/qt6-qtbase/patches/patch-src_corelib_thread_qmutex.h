--- src/corelib/thread/qmutex.h.orig	2026-06-04 16:29:11 UTC
+++ src/corelib/thread/qmutex.h
@@ -25,11 +25,15 @@ class QT6_ONLY(Q_CORE_EXPORT) QBasicMute
     Q_DISABLE_COPY_MOVE(QBasicMutex)
 protected:
     static constexpr bool FutexAlwaysAvailable =
+#  if defined(__DragonFly__)
+            false
+#  else
 #if defined(Q_OS_FREEBSD) || defined(Q_OS_LINUX) || defined(Q_OS_WIN) || defined(Q_OS_APPLE) // these platforms use futex
             true
 #else
             false
 #endif
+#  endif
             ;
 
 public:
