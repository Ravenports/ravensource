--- src/corelib/global/qfloat16.h.orig	2020-10-27 08:02:11 UTC
+++ src/corelib/global/qfloat16.h
@@ -43,6 +43,7 @@
 
 #include <QtCore/qglobal.h>
 #include <QtCore/qmetatype.h>
+#include <limits>
 #include <string.h>
 
 #if defined(QT_COMPILER_SUPPORTS_F16C) && defined(__AVX2__) && !defined(__F16C__)
