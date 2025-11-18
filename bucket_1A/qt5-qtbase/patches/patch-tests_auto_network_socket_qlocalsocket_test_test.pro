--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2024-05-08 05:17:16 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
