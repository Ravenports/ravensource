--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2019-10-25 07:16:48 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
