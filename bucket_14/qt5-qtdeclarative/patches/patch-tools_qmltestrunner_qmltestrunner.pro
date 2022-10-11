--- tools/qmltestrunner/qmltestrunner.pro.orig	2022-08-16 17:37:22 UTC
+++ tools/qmltestrunner/qmltestrunner.pro
@@ -1,6 +1,6 @@
 SOURCES += main.cpp
 
-QT += qml qmltest
+QT += qml quick qmltest
 CONFIG += no_import_scan
 
 QMAKE_TARGET_DESCRIPTION = QML Test Runner
