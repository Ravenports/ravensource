--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2024-05-08 05:14:41 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
