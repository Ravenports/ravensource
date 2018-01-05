--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2017-11-30 13:49:46 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -1017,7 +1017,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_GROUP_get_degree)
 #endif
     RESOLVEFUNC(BN_num_bits)
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if QT_CONFIG(opensslv11)
     RESOLVEFUNC(BN_is_word)
 #endif
     RESOLVEFUNC(BN_mod_word)
