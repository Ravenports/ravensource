--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2024-07-23 10:25:47 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
