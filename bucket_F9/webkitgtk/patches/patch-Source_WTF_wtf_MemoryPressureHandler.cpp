--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2021-02-26 09:57:08 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -57,7 +57,7 @@ MemoryPressureHandler& MemoryPressureHan
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
