--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2021-01-26 18:29:22 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
