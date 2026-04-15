--- examples/ThumbNailer/AverageLoadManager.cpp.orig	2026-03-07 20:34:13 UTC
+++ examples/ThumbNailer/AverageLoadManager.cpp
@@ -8,6 +8,10 @@
 
 #include "AverageLoadManager.h"
 
+#ifdef __sun
+#include <sys/loadavg.h>
+#endif
+
 AverageLoadManager::AverageLoadManager(QObject *parent)
     : QObject(parent)
     , m_timer(new QTimer(this))
