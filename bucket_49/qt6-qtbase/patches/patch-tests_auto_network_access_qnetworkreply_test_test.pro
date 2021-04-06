--- tests/auto/network/access/qnetworkreply/test/test.pro.orig	2021-02-11 10:23:05 UTC
+++ tests/auto/network/access/qnetworkreply/test/test.pro
@@ -14,6 +14,7 @@ TESTDATA += ../empty ../rfc3252.txt ../r
             ../index.html ../smb-file.txt
 
 !android: TEST_HELPER_INSTALLS = ../echo/echo
+solaris: LIBS += -lsocket
 
 CONFIG += unsupported/testserver
 QT_TEST_SERVER_LIST = vsftpd apache2 ftp-proxy danted squid
