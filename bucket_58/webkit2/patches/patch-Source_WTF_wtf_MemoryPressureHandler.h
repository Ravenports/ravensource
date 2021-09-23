--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2021-09-01 09:16:49 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -69,7 +69,7 @@ public:
 
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -263,7 +263,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     RunLoop::Timer<MemoryPressureHandler> m_holdOffTimer;
     void holdOffTimerFired();
 #endif
