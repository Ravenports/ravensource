--- src/widget.cc.orig	2023-09-12 21:06:50 UTC
+++ src/widget.cc
@@ -22,6 +22,10 @@
 
 #include <sys/wait.h> // for W_EXITCODE
 
+#ifndef W_EXITCODE
+#define W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
+#endif
+
 #include <exception>
 #include <new>
 #include <stdexcept>
