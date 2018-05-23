--- config.tests/iconv/iconv.pro.orig	2018-05-14 04:46:28 UTC
+++ config.tests/iconv/iconv.pro
@@ -1,2 +1,2 @@
 SOURCES = iconv.cpp
-mac|mingw|openbsd|qnx|haiku:LIBS += -liconv
+LIBS += -liconv
