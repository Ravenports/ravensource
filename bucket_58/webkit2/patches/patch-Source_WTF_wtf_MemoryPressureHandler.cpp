--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2022-02-23 11:41:47 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -56,7 +56,7 @@ MemoryPressureHandler& MemoryPressureHan
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
