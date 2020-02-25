--- openbsd-compat/arc4random.c.orig	2020-02-10 22:53:01 UTC
+++ openbsd-compat/arc4random.c
@@ -163,6 +163,7 @@ _rs_random_u32(uint32_t *val)
 	return;
 }
 
+#if !defined(HAVE_ARC4RANDOM) && !defined(LIBRESSL_VERSION_NUMBER)
 void
 arc4random_stir(void)
 {
@@ -170,6 +171,7 @@ arc4random_stir(void)
 	_rs_stir();
 	_ARC4_UNLOCK();
 }
+#endif
 
 void
 arc4random_addrandom(u_char *dat, int datlen)
