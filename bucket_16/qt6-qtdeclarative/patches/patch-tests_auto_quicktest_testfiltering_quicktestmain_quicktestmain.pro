--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2021-01-27 22:35:57 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
