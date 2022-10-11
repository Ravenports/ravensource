--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2022-06-24 10:42:02 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
