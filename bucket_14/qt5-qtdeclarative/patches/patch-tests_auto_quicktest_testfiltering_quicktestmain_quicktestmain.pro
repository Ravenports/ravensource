--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2022-08-16 17:37:22 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
