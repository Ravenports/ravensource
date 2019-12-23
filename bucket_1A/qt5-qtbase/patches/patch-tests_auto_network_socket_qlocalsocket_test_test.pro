--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2019-12-07 06:27:07 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
