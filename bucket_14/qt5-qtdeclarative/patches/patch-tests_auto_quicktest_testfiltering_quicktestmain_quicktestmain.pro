--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2023-04-24 07:13:40 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
