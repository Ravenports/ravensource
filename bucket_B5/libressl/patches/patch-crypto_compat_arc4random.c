--- crypto/compat/arc4random.c.orig	2018-08-05 18:01:56 UTC
+++ crypto/compat/arc4random.c
@@ -88,7 +88,7 @@ _rs_stir(void)
 	u_char rnd[KEYSZ + IVSZ];
 
 	if (getentropy(rnd, sizeof rnd) == -1)
-		_getentropy_fail();
+	; /*	_getentropy_fail(); */
 
 	if (!rs)
 		_rs_init(rnd, sizeof(rnd));
