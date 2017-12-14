--- lib/crypto/c_src/crypto.c.orig	2017-12-08 09:57:52 UTC
+++ lib/crypto/c_src/crypto.c
@@ -4596,20 +4596,7 @@ static ERL_NIF_TERM pkey_crypt_nif(ErlNi
 	if (crypt_opt.signature_md != NULL
 	    && EVP_PKEY_CTX_set_signature_md(ctx, crypt_opt.signature_md) <= 0)
 		goto badarg;
-	if (crypt_opt.rsa_padding == RSA_SSLV23_PADDING) {
-	    if (is_encrypt) {
-		RSA *rsa = EVP_PKEY_get1_RSA(pkey);
-		if (rsa == NULL) goto badarg;
-		tmplen = RSA_size(rsa);
-		if (!enif_alloc_binary(tmplen, &tmp_bin)) goto badarg;
-		if (RSA_padding_add_SSLv23(tmp_bin.data, tmplen, in_bin.data, in_bin.size) <= 0)
-		    goto badarg;
-		in_bin = tmp_bin;
-	    }
-	    if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_NO_PADDING) <= 0) goto badarg;
-	} else {
-	    if (EVP_PKEY_CTX_set_rsa_padding(ctx, crypt_opt.rsa_padding) <= 0) goto badarg;
-	}
+	if (EVP_PKEY_CTX_set_rsa_padding(ctx, crypt_opt.rsa_padding) <= 0) goto badarg;
 #ifdef HAVE_RSA_OAEP_MD
 	if (crypt_opt.rsa_padding == RSA_PKCS1_OAEP_PADDING) {
 	    if (crypt_opt.rsa_oaep_md != NULL
@@ -4727,26 +4714,6 @@ static ERL_NIF_TERM pkey_crypt_nif(ErlNi
     RSA_free(rsa);
 #endif
 
-    if ((i > 0) && argv[0] == atom_rsa && !is_encrypt) {
-	if (crypt_opt.rsa_padding == RSA_SSLV23_PADDING) {
-	    RSA *rsa = EVP_PKEY_get1_RSA(pkey);
-	    unsigned char *p;
-	    if (rsa == NULL) goto badarg;
-	    tmplen = RSA_size(rsa);
-	    if (!enif_alloc_binary(tmplen, &tmp_bin)) goto badarg;
-	    p = out_bin.data;
-	    p++;
-	    i = RSA_padding_check_SSLv23(tmp_bin.data, tmplen, p, out_bin.size - 1, tmplen);
-	    if (i >= 0) {
-		outlen = i;
-		in_bin = out_bin;
-		out_bin = tmp_bin;
-		tmp_bin = in_bin;
-		i = 1;
-	    }
-	}
-    }
-
     if (tmp_bin.data != NULL) {
 	enif_release_binary(&tmp_bin);
     }
