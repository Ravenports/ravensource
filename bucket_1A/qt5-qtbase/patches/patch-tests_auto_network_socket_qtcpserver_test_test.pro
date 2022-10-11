--- tests/auto/network/socket/qtcpserver/test/test.pro.orig	2022-06-24 10:42:02 UTC
+++ tests/auto/network/socket/qtcpserver/test/test.pro
@@ -16,6 +16,7 @@ win32 {
 QT = core network testlib
 
 MOC_DIR=tmp
+solaris: LIBS+= -lsocket
 
 # Only on Linux until cyrus has been added to docker-compose-for-{windows,macOS}.yml and tested
 linux {
