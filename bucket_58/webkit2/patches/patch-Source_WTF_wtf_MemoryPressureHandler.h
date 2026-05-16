--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -98,7 +98,7 @@ public:
     WTF_EXPORT_PRIVATE void setMemoryFootprintPollIntervalForTesting(Seconds);
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -269,7 +269,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     RunLoop::Timer m_holdOffTimer;
     void holdOffTimerFired();
 #endif
