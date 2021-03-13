--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2021-02-25 00:57:23 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
