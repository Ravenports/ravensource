--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2021-09-01 09:16:49 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -56,7 +56,7 @@ MemoryPressureHandler& MemoryPressureHan
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
