--- config.tests/iconv/iconv.pro.orig	2018-12-03 11:15:26 UTC
+++ config.tests/iconv/iconv.pro
@@ -1,2 +1,2 @@
 SOURCES = iconv.cpp
-mac|mingw|openbsd|qnx|haiku:LIBS += -liconv
+LIBS += -liconv
