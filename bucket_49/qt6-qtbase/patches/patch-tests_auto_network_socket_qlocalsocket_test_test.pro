--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2021-02-11 10:23:05 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
