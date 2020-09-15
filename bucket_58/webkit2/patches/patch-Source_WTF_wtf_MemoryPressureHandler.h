--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2020-08-12 09:17:54 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -66,7 +66,7 @@ public:
 
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -200,7 +200,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     RunLoop::Timer<MemoryPressureHandler> m_holdOffTimer;
     void holdOffTimerFired();
 #endif
