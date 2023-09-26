--- Source/WTF/wtf/MemoryPressureHandler.h.orig	2023-08-09 08:49:39 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.h
@@ -81,7 +81,7 @@ public:
 
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__) || defined(__MidnightBSD__)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -293,7 +293,7 @@ private:
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__) || defined(__MidnightBSD__)
     RunLoop::Timer m_holdOffTimer;
     void holdOffTimerFired();
 #endif
