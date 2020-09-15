--- Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2020-08-12 09:17:54 UTC
+++ Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -53,7 +53,7 @@ MemoryPressureHandler& MemoryPressureHan
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(FREEBSD) || defined(__DragonFly__)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
