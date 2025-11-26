--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2024-11-08 13:36:08 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
