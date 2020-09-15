--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2020-08-24 09:20:54 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
