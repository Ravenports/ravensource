--- tests/auto/network/socket/qlocalsocket/test/test.pro.orig	2025-06-05 14:07:26 UTC
+++ tests/auto/network/socket/qlocalsocket/test/test.pro
@@ -19,3 +19,4 @@ CONFIG(debug_and_release) {
   DESTDIR = ..
 }
 
+solaris: LIBS += -lsocket
