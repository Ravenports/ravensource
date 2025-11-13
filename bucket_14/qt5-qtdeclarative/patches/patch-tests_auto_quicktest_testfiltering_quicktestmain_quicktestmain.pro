--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2023-10-11 13:01:30 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
