--- src/mul.c.orig	2017-12-30 22:11:00.188369000 +0100
+++ src/mul.c	2017-12-30 22:17:31.900188000 +0100
@@ -170,9 +170,9 @@
    return MPC_INEX (inex_re, inex_im);
 }
 
-
+#if HAVE_MPFR_FMMA == 0
 static int
-mpfr_fmma (mpfr_ptr z, mpfr_srcptr a, mpfr_srcptr b, mpfr_srcptr c,
+mpc_fmma (mpfr_ptr z, mpfr_srcptr a, mpfr_srcptr b, mpfr_srcptr c,
            mpfr_srcptr d, int sign, mpfr_rnd_t rnd)
 {
    /* Computes z = ab+cd if sign >= 0, or z = ab-cd if sign < 0.
@@ -319,7 +319,7 @@
 
    return inex;
 }
-
+#endif
 
 int
 mpc_mul_naive (mpc_ptr z, mpc_srcptr x, mpc_srcptr y, mpc_rnd_t rnd)
@@ -337,10 +337,17 @@
    else
       rop [0] = z [0];
 
-   inex = MPC_INEX (mpfr_fmma (mpc_realref (rop), mpc_realref (x), mpc_realref (y), mpc_imagref (x),
-                               mpc_imagref (y), -1, MPC_RND_RE (rnd)),
+#if HAVE_MPFR_FMMA
+   inex = MPC_INEX (mpfr_fmms (mpc_realref (rop), mpc_realref (x), mpc_realref (y), mpc_imagref (x),
+				mpc_imagref (y), MPC_RND_RE (rnd)),
                     mpfr_fmma (mpc_imagref (rop), mpc_realref (x), mpc_imagref (y), mpc_imagref (x),
+				mpc_realref (y), MPC_RND_IM (rnd)));
+#else
+   inex = MPC_INEX (mpc_fmma (mpc_realref (rop), mpc_realref (x), mpc_realref (y), mpc_imagref (x),
+				mpc_imagref (y), -1, MPC_RND_RE (rnd)),
+		mpc_fmma (mpc_imagref (rop), mpc_realref (x), mpc_imagref (y), mpc_imagref (x),
                                mpc_realref (y), +1, MPC_RND_IM (rnd)));
+#endif
 
    mpc_set (z, rop, MPC_RNDNN);
    if (overlap)
