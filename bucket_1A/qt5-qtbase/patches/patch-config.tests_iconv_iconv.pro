--- config.tests/iconv/iconv.pro.orig	2018-11-25 12:51:11 UTC
+++ config.tests/iconv/iconv.pro
@@ -1,2 +1,2 @@
 SOURCES = iconv.cpp
-mac|mingw|openbsd|qnx|haiku:LIBS += -liconv
+LIBS += -liconv
