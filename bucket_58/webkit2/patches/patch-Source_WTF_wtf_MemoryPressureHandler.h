--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -93,7 +93,7 @@ public:
     WTF_EXPORT_PRIVATE void setMemoryFootprintPollIntervalForTesting(Seconds);
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -262,7 +262,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     RunLoop::Timer m_holdOffTimer;
     void holdOffTimerFired();
 #endif
