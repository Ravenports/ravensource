--- tests/auto/network/socket/qtcpserver/test/test.pro.orig	2024-11-08 13:36:08 UTC
+++ tests/auto/network/socket/qtcpserver/test/test.pro
@@ -16,6 +16,7 @@ win32 {
 QT = core network testlib
 
 MOC_DIR=tmp
+solaris: LIBS+= -lsocket
 
 # Only on Linux until cyrus has been added to docker-compose-for-{windows,macOS}.yml and tested
 linux {
