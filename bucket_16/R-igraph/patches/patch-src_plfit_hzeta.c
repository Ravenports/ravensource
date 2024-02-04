NetBSD does not support log1pl

--- src/vendor/cigraph/vendor/plfit/hzeta.c.orig	2024-01-21 22:35:55 UTC
+++ src/vendor/cigraph/vendor/plfit/hzeta.c
@@ -401,7 +401,7 @@ double hsl_sf_hzeta_deriv2(const double
 
 static inline
 double hsl_sf_hZeta0_zed(const double s, const double q) {
-#if 1
+#if !defined(__NetBSD__)
 	const long double ld_q=(long double)(q);
 	const long double ld_s=(long double)(s);
 	const long double ld_log1prq=log1pl(1.0L/ld_q);
@@ -477,7 +477,7 @@ int hsl_sf_hZeta0(const double s, const
 
 static inline
 double hsl_sf_hZeta1_zed(const double s, const double q) {
-#if 1
+#if !defined(__NetBSD__) 
 	const long double ld_q=(long double)(q);
 	const long double ld_s=(long double)(s);
 	const long double ld_sm1=ld_s-1.0L;
