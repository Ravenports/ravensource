--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2020-03-27 09:49:31 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
