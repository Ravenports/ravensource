--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -67,7 +67,7 @@ static MemoryPressureHandler* memoryPres
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     : m_holdOffTimer(RunLoop::mainSingleton(), "MemoryPressureHandler::HoldOffTimer"_s, this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::mainSingleton(), "MemoryPressureHandler::WindowsMeasurementTimer"_s, this, &MemoryPressureHandler::windowsMeasurementTimerFired)
