--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2021-02-09 18:01:03 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
