--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2020-05-11 08:06:12 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
