--- src/tds/tls.c.orig	2017-02-15 09:00:01 UTC
+++ src/tds/tls.c
@@ -50,6 +50,10 @@
 #include <sys/socket.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
+
 #include <freetds/tds.h>
 #include <freetds/string.h>
 #include <freetds/tls.h>
@@ -72,6 +76,12 @@
 #define SSL_PTR ptr
 #else
 
+#ifdef LIBRESSL_VERSION_NUMBER
+static pthread_mutex_t *openssllocks;
+#undef OPENSSL_VERSION_NUMBER
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+
 /* some compatibility layer */
 #if OPENSSL_VERSION_NUMBER < 0x1010000FL
 static inline void
