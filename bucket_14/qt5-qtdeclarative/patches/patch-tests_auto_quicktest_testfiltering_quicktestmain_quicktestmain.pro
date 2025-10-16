--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2023-06-09 14:08:47 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
