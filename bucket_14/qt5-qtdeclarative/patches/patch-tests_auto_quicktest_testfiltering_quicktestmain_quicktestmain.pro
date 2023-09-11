--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2023-03-23 14:00:07 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
