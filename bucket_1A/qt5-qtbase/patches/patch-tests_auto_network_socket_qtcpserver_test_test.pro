--- tests/auto/network/socket/qtcpserver/test/test.pro.orig	2025-06-05 14:07:26 UTC
+++ tests/auto/network/socket/qtcpserver/test/test.pro
@@ -16,6 +16,7 @@ win32 {
 QT = core network testlib
 
 MOC_DIR=tmp
+solaris: LIBS+= -lsocket
 
 # Only on Linux until cyrus has been added to docker-compose-for-{windows,macOS}.yml and tested
 linux {
