--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2023-04-24 13:43:14 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
