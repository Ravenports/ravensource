--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2022-02-23 11:41:47 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -81,7 +81,7 @@ public:
 
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -277,7 +277,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     RunLoop::Timer<MemoryPressureHandler> m_holdOffTimer;
     void holdOffTimerFired();
 #endif
