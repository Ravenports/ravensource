--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2021-03-24 09:19:47 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
