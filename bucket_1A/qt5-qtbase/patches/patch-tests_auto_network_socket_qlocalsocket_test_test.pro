--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2023-06-09 14:30:54 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
