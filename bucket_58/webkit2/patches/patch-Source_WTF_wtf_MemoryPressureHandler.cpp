--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2024-03-16 06:45:49 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -65,7 +65,7 @@ static MemoryPressureHandler* memoryPres
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD) || OS(QNX)
+#if OS(LINUX) || OS(FREEBSD) || OS(QNX) || defined(__DragonFly__) || defined(__MidnightBSD__)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
