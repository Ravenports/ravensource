--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2023-10-17 12:50:53 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
