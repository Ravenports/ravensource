--- tools/qmltestrunner/qmltestrunner.pro.orig	2019-10-18 12:18:05 UTC
+++ tools/qmltestrunner/qmltestrunner.pro
@@ -1,6 +1,6 @@
 SOURCES += main.cpp
 
-QT += qml qmltest
+QT += qml quick qmltest
 CONFIG += no_import_scan
 
 QMAKE_TARGET_DESCRIPTION = QML Test Runner
