--- config.tests/iconv/iconv.pro.orig	2017-11-30 13:49:46 UTC
+++ config.tests/iconv/iconv.pro
@@ -1,2 +1,2 @@
 SOURCES = iconv.cpp
-mac|mingw|openbsd|qnx|haiku:LIBS += -liconv
+LIBS += -liconv
