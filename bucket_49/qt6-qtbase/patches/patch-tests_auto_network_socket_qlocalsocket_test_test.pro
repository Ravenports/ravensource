--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2020-10-27 08:02:11 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
