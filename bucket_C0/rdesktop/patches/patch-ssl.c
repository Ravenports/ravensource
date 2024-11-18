--- ssl.c.orig	2019-09-19 10:34:03 UTC
+++ ssl.c
@@ -307,10 +307,10 @@ rdssl_rkey_get_exp_mod(RDSSL_RKEY * rkey
 {
 	size_t outlen;
 
-	outlen = (mpz_sizeinbase(modulus, 2) + 7) / 8;
+	outlen = (mpz_sizeinbase((mpz_srcptr)modulus, 2) + 7) / 8;
 	if (outlen > max_mod_len)
 		return 1;
-	outlen = (mpz_sizeinbase(exponent, 2) + 7) / 8;
+	outlen = (mpz_sizeinbase((mpz_srcptr)exponent, 2) + 7) / 8;
 	if (outlen > max_exp_len)
 		return 1;
 
