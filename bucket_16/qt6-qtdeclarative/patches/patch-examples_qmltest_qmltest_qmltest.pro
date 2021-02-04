--- examples/qmltest/qmltest/qmltest.pro.orig	2021-01-27 22:35:57 UTC
+++ examples/qmltest/qmltest/qmltest.pro
@@ -14,7 +14,7 @@ TESTDATA += tst_basic.qml tst_item.qml
 # This code exists solely for the purpose of building this example
 # inside the examples/ hierarchy.
 
-QT += qml qmltest
+QT += qml quick qmltest
 
 macx: CONFIG -= app_bundle
 
