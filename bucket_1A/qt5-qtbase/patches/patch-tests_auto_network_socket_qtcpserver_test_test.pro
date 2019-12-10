--- tests/auto/network/socket/qtcpserver/test/test.pro.orig	2019-10-25 07:16:48 UTC
+++ tests/auto/network/socket/qtcpserver/test/test.pro
@@ -16,3 +16,4 @@ win32 {
 QT = core network testlib
 
 MOC_DIR=tmp
+solaris: LIBS+= -lsocket
