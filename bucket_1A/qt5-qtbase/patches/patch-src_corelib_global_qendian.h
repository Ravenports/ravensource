--- src/corelib/global/qendian.h.orig	2020-10-27 08:02:11 UTC
+++ src/corelib/global/qendian.h
@@ -44,6 +44,8 @@
 #include <QtCore/qfloat16.h>
 #include <QtCore/qglobal.h>
 
+#include <limits>
+
 // include stdlib.h and hope that it defines __GLIBC__ for glibc-based systems
 #include <stdlib.h>
 #include <string.h>
