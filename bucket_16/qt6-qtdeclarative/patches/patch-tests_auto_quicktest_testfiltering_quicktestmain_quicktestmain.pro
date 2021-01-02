--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2020-12-04 15:55:25 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
