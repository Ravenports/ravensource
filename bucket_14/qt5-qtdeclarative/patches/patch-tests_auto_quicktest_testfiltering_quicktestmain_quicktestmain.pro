--- tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro.orig	2025-06-05 21:08:43 UTC
+++ tests/auto/quicktest/testfiltering/quicktestmain/quicktestmain.pro
@@ -1,3 +1,4 @@
+QT += quick
 CONFIG += qmltestcase
 macos:CONFIG -= app_bundle
 TARGET = quicktestmain
