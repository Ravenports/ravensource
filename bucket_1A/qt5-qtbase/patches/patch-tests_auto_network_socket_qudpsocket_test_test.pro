--- tests/auto/network/socket/qudpsocket/test/test.pro.orig	2019-10-25 07:16:48 UTC
+++ tests/auto/network/socket/qudpsocket/test/test.pro
@@ -17,3 +17,4 @@ win32 {
 }
 
 TARGET = tst_qudpsocket
+solaris: LIBS+= -lsocket
