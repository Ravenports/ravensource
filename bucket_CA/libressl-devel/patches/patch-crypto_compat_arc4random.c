--- crypto/compat/arc4random.c.orig	2025-10-28 13:16:23 UTC
+++ crypto/compat/arc4random.c
@@ -91,7 +91,7 @@ _rs_stir(void)
 	uint32_t rekey_fuzz = 0;
 
 	if (getentropy(rnd, sizeof rnd) == -1)
-		_getentropy_fail();
+	; /*	_getentropy_fail(); */
 
 	if (!rs)
 		_rs_init(rnd, sizeof(rnd));
