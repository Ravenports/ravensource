--- openbsd-compat/arc4random.c.orig	2024-04-20 06:57:04 UTC
+++ openbsd-compat/arc4random.c
@@ -155,6 +155,7 @@ _rs_random_u32(uint32_t *val)
 	return;
 }
 
+#if !defined(HAVE_ARC4RANDOM) && !defined(LIBRESSL_VERSION_NUMBER)
 void
 arc4random_stir(void)
 {
@@ -162,6 +163,7 @@ arc4random_stir(void)
 	_rs_stir();
 	_ARC4_UNLOCK();
 }
+#endif
 
 void
 arc4random_addrandom(u_char *dat, int datlen)
