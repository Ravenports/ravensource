--- qt/DetailsDialog.cc.orig	2026-10-23 00:18:54 UTC
+++ qt/DetailsDialog.cc
@@ -28,6 +28,7 @@
 #include <QString>
 #include <QStyle>
 #include <QTreeWidgetItem>
+#include <QFile>
 
 #include <libtransmission/transmission.h>
 #include <libtransmission/announce-list.h>
