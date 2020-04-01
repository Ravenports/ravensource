--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2020-03-03 13:10:32 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
