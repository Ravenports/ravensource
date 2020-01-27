--- tests/auto/network/ssl/ssl.pro.orig	2020-01-23 12:37:32 UTC
+++ tests/auto/network/ssl/ssl.pro

qsslcertificate not compiled with includes for openssl

@@ -3,7 +3,6 @@ QT_FOR_CONFIG += network-private
 
 SUBDIRS=\
    qpassworddigestor \
-   qsslcertificate \
    qsslcipher \
    qsslellipticcurve \
    qsslerror \
