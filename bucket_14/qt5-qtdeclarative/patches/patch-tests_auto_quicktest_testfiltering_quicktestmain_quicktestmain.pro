--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2019-12-05 10:23:52 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
