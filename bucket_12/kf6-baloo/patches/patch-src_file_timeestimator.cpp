--- src/file/timeestimator.cpp.orig	2026-03-07 20:28:47 UTC
+++ src/file/timeestimator.cpp
@@ -24,7 +24,7 @@ uint TimeEstimator::calculateTimeLeft()
 
     int bufferIndex = m_bufferIndex;
     for (int i = 0; i < BUFFER_SIZE; ++i) {
-        float weight = sqrt(i + 1);
+        float weight = sqrt(i + 1.0);
         totalWeight += weight;
 
         totalTime += m_batchTimeBuffer[bufferIndex] * weight;
