--- tests/auto/network/socket/qtcpserver/test/test.pro.orig	2023-03-23 19:06:47 UTC
+++ tests/auto/network/socket/qtcpserver/test/test.pro
@@ -16,6 +16,7 @@ win32 {
 QT = core network testlib
 
 MOC_DIR=tmp
+solaris: LIBS+= -lsocket
 
 # Only on Linux until cyrus has been added to docker-compose-for-{windows,macOS}.yml and tested
 linux {
