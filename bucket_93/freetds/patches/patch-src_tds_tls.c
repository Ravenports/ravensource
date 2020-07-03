--- src/tds/tls.c.orig	2020-05-31 12:36:24 UTC
+++ src/tds/tls.c
@@ -53,6 +53,10 @@
 #include <sys/socket.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
+
 #include <freetds/tds.h>
 #include <freetds/utils/string.h>
 #include <freetds/tls.h>
@@ -75,6 +79,15 @@
 #define SSL_PTR ptr
 #else
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#if LIBRESSL_VERSION_NUMBER < 0x2070000FL
+static pthread_mutex_t *openssllocks;
+#undef OPENSSL_VERSION_NUMBER
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+#define TLS_ST_OK SSL_ST_OK
+#endif
+
 /* some compatibility layer */
 #if !HAVE_BIO_GET_DATA
 static inline void
